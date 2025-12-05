# include <stdio.h>
void month_day(int year, int yearday, int* pmonth, int* pday);

int main(void)
{
    int day, month, year, yearday;     /*  定义代表日、月、年和天数的变量*/
    scanf("%d%d", &year, &yearday);
    month_day(year, yearday, &month, &day);/* 调用计算月、日函数  */
    printf("%d %d %d\n", year, month, day);
    return 0;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
    int arr1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int arr2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        *pmonth = 0;
        *pday = 0;
        while (1)
        {
            (*pmonth)++;///
            yearday -= arr1[*pmonth - 1];
            if (yearday < 0)
            {
                *pday = yearday + arr1[*pmonth - 1];
                if (*pday == 0)
                {
                    *pday = arr1[*pmonth - 1 - 1];
                    (*pmonth)--;
                }
                break;
            }
        }
    }
    else
    {
        *pmonth = 0;
        *pday = 0;
        while (1)
        {
            (*pmonth)++;///这里注意运算符的优先级
            yearday -= arr2[*pmonth - 1];
            if (yearday < 0)
            {
                *pday = yearday + arr1[*pmonth - 1];
                if (*pday == 0)
                {
                    *pday = arr2[*pmonth - 1 - 1];
                    (*pmonth)--;
                }
                break;
            }
        }
    }
}

