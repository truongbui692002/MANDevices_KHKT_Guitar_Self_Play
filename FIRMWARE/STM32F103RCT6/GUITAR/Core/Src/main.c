/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "servo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint32_t Bai1[] = {
  0b00011111000000010000001000000010,  
  0b00100001000000100010010000000000,
  0b00111110000000000000001100000010, ///////
  0b00110001000000001000000100000010,
  0b00101101000000010000001000000000,
  0b00101001000000000000000000000000,
  0b00101000000000000000000000000000,
  0b00101001000000000000000000000000,
  0b00101000000000000000000000000000,
  0b00101010000000000000000000000010,
  0b00000100000000100000000000000000,
  0b00000110000000000000000000000000,
  0b00000100000000000000000000000000,
  0b00000000000000000010000000000000, ////
  0b00000010000000000000000000000010,
  0b00000000000000000000000000000000,
  0b00000010000000000000000000000000,
  0b00010100000000000000000010000000,
  0b00010000000000000000000100000000,
  0b00010010000000000000000000000010,
  0b00010000000000000000000000000010,
  0b00010010000000000000000000000010,
  0b00010110000000000000000000000000,
  0b00011010000000001000000100000000,
  0b00011000000000000000000000000010,
  0b00011100000000000000000010000000,
  0b00011101000000000000000000000000,
  0b00011100000000000000000000000000,
  0b00011110000000000010000000000000,
  0b00011100000000000000000000000010,
  0b00001010000000010000000000000010,
  0b00000010000000000000001000000000,
  0b00000110000000000000000000000000,
  0b00000111000000000000000000000000,
  0b00000110000000000000000000000000,
  0b00000111000000000000000000000000,
  0b00000101000000000000000000000010,
  0b00101011000000100000000000000000,
  0b00101001000000000000000000000000,
  0b00100001000000000000000000000000,
  0b00100011000000000010000000000000,
  0b00100001000000000010000000000000,
  0b00100011000000000010000000000000,
  0b00100001000000000010000000000000,
  0b00110010000000000000000000000010,
  0b00110011000000000001000000000000,
  0b00110010000000000000000000000000,
  0b00111010000000000000001000000000,
  0b00111011000000000000000000000000,
  0b00111010000000000000000000000000,
  0b00111000000000000000000000000010,
  0b00111100000000000000000000000000,
  0b00110100000000001000000000000000,
  0b00110000000000000000000100000000,
  0b00110001000000000000000000000000,
  0b00110011000000000010000000000000,
  0b00110001000000000010000000000000,
  0b00110011000000000000000000000010,
  0b00101101000000010000001000000010,
  0b00111101000000010000000000000000,///
  0b00110101000000000000001000000000,
  0b00111101000000000000001000000000, //
  0b00110101000000000000001000000000,
  0b00111101000000000000001000000000,
  0b00110101000000000000001000000000,
  0b00111101000000000000000000000000,
  0b00010101000000100000000000000000,
  0b00110101000000100000000000000000,
  0b00111101000000000000000000000000,
  0b00101101000000010000000000000000,
  0b00101001000000000000000000000000,
  0b00101101000000000000000000000000,
  0b00100101000000000000001000000000,
  0b00110101000000010000000000000000,
  0b00000101000000000000000000000000,
  0b00010101000000000000000000000000,
  0b00011101000000000000000000000000,
  0b00010101000000000000001000000000,
  0b00011101000000000000000000000000,
  0b00010101000000000000000000000000,
  0b00011101000000000000001000000000,
  0b00010101000000000000000000000000,
  0b00000101000000010000000000000000,
  0b00101101000000000000001000100000,
  0b00100101000000001000000000000000,
  0b00101101000000000000001000000000,
  0b00100101000000000000001000000000,
  0b00110101000000000000010000000000,
  0b00100101000000010000000000000000,
  0b00110101000000010000000000000000,
  0b00100101010000000000000000000000,
  0b00111011000000010000001000000010,
  0b00101011000000010000000000000000,
  0b00100011000000000000001000000000,
  0b00101011000000000000001000000000,
  0b00100011000000000000001000000000,
  0b00101011000000000000001000000000,
  0b00100011000000000000001000000000,
  0b00101011000000000000000000000000,
  0b00000011000000100000000000000000,
  0b00100011000000100000000000000000,
  0b00101011000000000000000000000000,
  0b00100011000000000000000000000000,
  0b00100111000000000000000000000000,
  0b00100011000000000000000000000000,
  0b00100111000000000000000100000000,
  0b00100011000000000000000000000000,
  0b00100111000000000000000100000000,
  0b00001111100000000000001000000000,
  0b00001011000000000000000000000000,
  0b00011011000000010000000000000000
};
/* Define for 6 servo gay */
  servo_t servo_w_1 = {
    &htim1,
    TIM_CHANNEL_1
  };
  servo_t servo_w_2 = {
    &htim1,
    TIM_CHANNEL_2
  };
  servo_t servo_w_3 = {
    &htim1,
    TIM_CHANNEL_3
  };
  servo_t servo_w_4 = {
    &htim1,
    TIM_CHANNEL_4
  };
  servo_t servo_w_5 = {
    &htim2,
    TIM_CHANNEL_1
  };
  servo_t servo_w_6 = {
    &htim2,
    TIM_CHANNEL_2
  };

/*Define for 24 servo nhan */

  ///// Khoang 1 
    servo_t servo_k_1_1 = {
    &htim2,
    TIM_CHANNEL_4
  };
    servo_t servo_k_1_2 = {
    &htim2,
    TIM_CHANNEL_3
  };
    servo_t servo_k_1_3 = {
    &htim3,
    TIM_CHANNEL_4
  };
    servo_t servo_k_1_4 = {
    &htim3,
    TIM_CHANNEL_3
  };
    servo_t servo_k_1_5 = {
    &htim3,
    TIM_CHANNEL_2
  };
    servo_t servo_k_1_6 = {
    &htim3,
    TIM_CHANNEL_1
  };

  ///// Khoang 2
    servo_t servo_k_2_1 = {
    &htim5,
    TIM_CHANNEL_2
  };
    servo_t servo_k_2_2 = {
    &htim5,
    TIM_CHANNEL_1
  };
    servo_t servo_k_2_3 = {
    &htim4,
    TIM_CHANNEL_4
  };
    servo_t servo_k_2_4 = {
    &htim4,
    TIM_CHANNEL_3
  };
    servo_t servo_k_2_5 = {
    &htim4,
    TIM_CHANNEL_2
  };
    servo_t servo_k_2_6 = {
    &htim4,
    TIM_CHANNEL_1
  };

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_UART5_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  Servo_Init(&servo_w_1, servo_w_1.htim, servo_w_1.channel);
  Servo_Init(&servo_w_2, servo_w_2.htim, servo_w_2.channel);
  Servo_Init(&servo_w_3, servo_w_3.htim, servo_w_3.channel);
  Servo_Init(&servo_w_4, servo_w_4.htim, servo_w_4.channel);
  Servo_Init(&servo_w_5, servo_w_5.htim, servo_w_5.channel);
  Servo_Init(&servo_w_6, servo_w_6.htim, servo_w_6.channel);

  Servo_Init(&servo_k_1_1, servo_k_1_1.htim, servo_k_1_1.channel);
  Set_servo_5p(&servo_k_1_1);
  Servo_Init(&servo_k_1_2, servo_k_1_2.htim, servo_k_1_2.channel);
  Set_servo_5p(&servo_k_1_2);
  Servo_Init(&servo_k_1_3, servo_k_1_3.htim, servo_k_1_3.channel);
  Set_servo_5p(&servo_k_1_3);
  Servo_Init(&servo_k_1_4, servo_k_1_4.htim, servo_k_1_4.channel);
  Set_servo_5p(&servo_k_1_4);
  Servo_Init(&servo_k_1_5, servo_k_1_5.htim, servo_k_1_5.channel);
  Set_servo_5p(&servo_k_1_5);
  Servo_Init(&servo_k_1_6, servo_k_1_6.htim, servo_k_1_6.channel);
  Set_servo_5p(&servo_k_1_6);

  Servo_Init(&servo_k_2_1, servo_k_2_1.htim, servo_k_2_1.channel);
  Servo_Init(&servo_k_2_2, servo_k_2_2.htim, servo_k_2_2.channel);
  Servo_Init(&servo_k_2_3, servo_k_2_3.htim, servo_k_2_3.channel);
  Servo_Init(&servo_k_2_4, servo_k_2_4.htim, servo_k_2_4.channel);
  Servo_Init(&servo_k_2_5, servo_k_2_5.htim, servo_k_2_5.channel);
  Servo_Init(&servo_k_2_6, servo_k_2_6.htim, servo_k_2_6.channel);

  for(uint8_t j = 0; j < sizeof(Bai1) / sizeof(int); j++)
  {
    uint32_t bitt = Bai1[j];
    HAL_UART_Transmit(&huart3, (uint8_t*)&bitt, 4, 1000);
  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    for(uint8_t i = 0; i < sizeof(Bai1) / sizeof(int); i++)
    {
      uint32_t bit = Bai1[i];

      if((bit & 0x0000001)) Set_servo_5p(&servo_k_1_1);            // bit 1 trong not nhac
      else Set_servo_9p(&servo_k_1_1);

      if(((bit >> 1) & 0x00000001)) Set_servo_5p(&servo_k_1_2);
      else Set_servo_9p(&servo_k_1_2);

      if(((bit >> 2) & 0x00000001)) Set_servo_5p(&servo_k_1_3);
      else Set_servo_9p(&servo_k_1_3);

      if(((bit >> 3) & 0x00000001)) Set_servo_5p(&servo_k_1_4);
      else Set_servo_9p(&servo_k_1_4);

      if(((bit >> 4) & 0x00000001)) Set_servo_5p(&servo_k_1_5);
      else Set_servo_9p(&servo_k_1_5);

      if(((bit >> 5) & 0x00000001)) Set_servo_5p(&servo_k_1_6);
      else Set_servo_9p(&servo_k_1_6);

      if(((bit >> 6) & 0x00000001)) Set_servo_5p(&servo_k_2_1);
      else Set_servo_9p(&servo_k_2_1);

      if(((bit >> 7) & 0x00000001)) Set_servo_5p(&servo_k_2_2);
      else Set_servo_9p(&servo_k_2_2);

      if(((bit >> 8) & 0x00000001)) Set_servo_5p(&servo_k_2_3);
      else Set_servo_9p(&servo_k_2_3);

      if(((bit >> 9) & 0x00000001)) Set_servo_5p(&servo_k_2_4);
      else Set_servo_9p(&servo_k_2_4);

      if(((bit >> 10) & 0x00000001)) Set_servo_5p(&servo_k_2_5);
      else Set_servo_9p(&servo_k_2_5);

      if(((bit >> 11) & 0x00000001)) Set_servo_5p(&servo_k_2_6);
      else Set_servo_9p(&servo_k_2_6);

      HAL_Delay(250);

      if(((bit >> 24) & 0x01)) {Set_servo_5p(&servo_w_1);}
      else 
        {
          Set_servo_9p(&servo_w_1);
          // HAL_Delay(100);
          // Set_servo_5p(&servo_w_1);
        }
      if(((bit >> 25) & 0x00000001)) {Set_servo_5p(&servo_w_2);}
      else 
        {
          Set_servo_9p(&servo_w_2);
          // HAL_Delay(100);
          // Set_servo_5p(&servo_w_2);
        }
      if(((bit >> 26) & 0x01)) {Set_servo_5p(&servo_w_3);}
      else 
        {
          Set_servo_9p(&servo_w_3);
          // HAL_Delay(100);
          // Set_servo_5p(&servo_w_3);
        }
      if(((bit >> 27) & 0x00000001)) {Set_servo_5p(&servo_w_4);}
      else 
        {
          Set_servo_9p(&servo_w_4);
          // HAL_Delay(100);
          // Set_servo_5p(&servo_w_4);
        }
      if(((bit >> 28) & 0x00000001)) {Set_servo_5p(&servo_w_5);}
      else 
        {
          Set_servo_9p(&servo_w_5);
          // HAL_Delay(100);
          // Set_servo_5p(&servo_w_5);
        }
      if(((bit >> 29) & 0x00000001)) {Set_servo_5p(&servo_w_6);}
      else 
        {
          Set_servo_9p(&servo_w_6);
          // HAL_Delay(100);
          // Set_servo_5p(&servo_w_6);
        }

      if((i != 1) && (i != 2) && (i != 3) && (i != 4) && (i != 5) && (i != 12) && (i != 19) && (i != 24) && (i != 25) && (i != 32) && (i != 39) && (i != 47) && (i != 52) && (i != 54) && (i != 59) && (i != 76) && (i != 85) && (i != 88) && (i != 95))
        {
          HAL_Delay(250);
        }
      else if((i ==1) || (i ==2) || (i ==3) || (i ==4) || (i ==5) || (i ==12) || (i ==19) || (i ==24) || (i ==25) || (i ==39) || (i ==47) || (i ==52) || (i ==59) || (i ==76) || (i ==85) || (i ==88) || (i ==95))
        {
          HAL_Delay(750);
        }
      else if((i ==32) || ( i == 54))
        {
          HAL_Delay(1250);
        }
    }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
