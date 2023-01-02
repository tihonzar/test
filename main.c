#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h.>

void matrix_A ( int ** A, int rows_A, int colums_A);
void matrix_B ( int ** B, int rows_B, int colums_B);
void max_min ( int ** A, int rows_A, int colums_A);
void matrix_print(int ** , int , int);
void transpose_B ( int ** B, int rows_B, int colums_B);
void mult_A_B ( int ** A, int rows_A, int colums_A, int ** B, int rows_B, int colums_B );
void sort_A(int** A, int rows_A, int colums_A);
void sum_rows_A_and_colums_B(int ** A, int rows_A, int colums_A, int ** B, int rows_B, int colums_B);

void mamory_alocate_matrics_A(int **A,int rows_A, int colums_A);
int main()
{
    int **A;
    int **B;
    int rows_A = 9;
    int rows_B = 9;
    int colums_A = 9;
    int colums_B = 7;
    int action;
    int E = 0;

      srand(time(NULL));

      mamory_alocate_matrics_A(A,rows_A,colums_A);
   /* A = (int **) calloc (rows_A, sizeof (int *));
     if( A == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < rows_A; i++)
    {
        A[i] = (int *) calloc (colums_A, sizeof (int));
        if(A[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }*/

    B = (int **) calloc (rows_B, sizeof (int *));
     if( B == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < rows_B; i++)
    {
        B[i] = (int *) calloc (colums_B, sizeof (int));
        if(B[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }

    printf("matrix A:\n");
    matrix_A(A,rows_A,colums_A);

    printf("matrix B:\n");
    matrix_B(B,rows_B,colums_B);

do
{
    system("cls");
    matrix_print(A,rows_A,colums_A);
    matrix_print(B,rows_B,colums_B);
    printf("select an action:\n");
    printf("1. Find the maximum and minimum element of the two-dimensional matrix A,that are above the main diagonal.\n");
    printf("2. Transpose the two-dimensional matrix B.\n");
    printf("3. Find the matrix product A×B.\n");
    printf("4. Sort the elements of array A in ascending order.\n");
    printf("5. Display the sum of the elements of the rows of the matrix A and the columns of the matrix B.\n");
    printf("6. Exit\n");
    scanf("%d", &action);
  if (action == 1)
  {
   max_min (A, rows_A, colums_A);
   system("pause");
  }
  else if(action == 2)
  {
   transpose_B (B, rows_B, colums_B);
   system("pause");
  }
  else if(action == 3)
  {
   mult_A_B (A, rows_A, colums_A, B, rows_B, colums_B);
   system("pause");
  }
  else if(action == 4)
  {
   sort_A (A, rows_A, colums_A);
   system("pause");
  }
  else if(action == 5)
  {
   sum_rows_A_and_colums_B (A, rows_A, colums_A, B, rows_B, colums_B);
   system("pause");
  }
  else if(action == 6)
  {
   E = 1;
  }
} while(E == 0);

    for (int i = 0; i < rows_A; i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < rows_B; i++)
    {
        free(B[i]);
    }
    free(B);
    return 0;
}

void matrix_A ( int ** A, int rows_A, int colums_A)
{
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 9;
 for(int i=0;i<rows_A;i++)
    {
        for(int j=0;j<colums_A;j++)
        {
                A[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
                printf("  %d  ",A[i][j]);
        }
         printf("\n");
    }
}

void matrix_B ( int ** B, int rows_B, int colums_B)
{
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 9;
 for(int i=0;i<rows_B;i++)
    {
        for(int j=0;j<colums_B;j++)
        {
                B[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
                printf("  %d  ",B[i][j]);
        }
         printf("\n");
    }
}

void matrix_print(int ** M , int rows , int colums)
{
 for(int i=0;i<rows;i++)
    {
        for(int j=0;j<colums;j++)
        {
                printf("  %d  ",M[i][j]);
        }
         printf("\n");
    }
    printf("\n\n");
}

void max_min ( int ** A, int rows_A, int colums_A)
{
   int max_element;
   int min_element;
    max_element = A[1][2];
    min_element = A[1][2];
    for(int i=0;i<rows_A;i++)
    {
        for(int j=0;j<colums_A;j++)
        {
            if(j>i)
            {
                if(max_element<A[i][j])
                {
                max_element = A[i][j];
                }
                else if(min_element>A[i][j])
                {
                min_element = A[i][j];
                }
            }
        }
    }
         printf("\n max_element =   %d  ",max_element);
         printf("\n min_element =   %d  ",min_element);
}

void transpose_B ( int ** B, int rows_B, int colums_B )
{
     int **T;
     int rows_T;
     int colums_T;
     rows_T = colums_B;
     colums_T = rows_B;
     T = (int **) calloc (rows_T, sizeof (int *));
     if( T == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < rows_T; i++)
    {
        T[i] = (int *) calloc (colums_T, sizeof (int));
        if(T[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    for(int i=0;i<rows_B;i++)
    {
        for(int j=0;j<colums_B;j++)
        {
            T[j][i]=B[i][j];
        }
    }
    matrix_print(T,rows_T,colums_T);
}

void mult_A_B ( int ** A, int rows_A, int colums_A, int ** B, int rows_B, int colums_B )
{
     int **D;
     int rows_D;
     int colums_D;
     int x;
     int y;
     rows_D = rows_A;
     colums_D = colums_B;
      D = (int **) calloc (rows_D, sizeof (int *));
     if( D == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < rows_D; i++)
    {
        D[i] = (int *) calloc (colums_D, sizeof (int));
        if(D[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
      for(int i=0;i<rows_D;i++)
    {
        for(int j=0;j<colums_D;j++)
        {
            x = 0;
            for(int p=0;p<rows_D;p++)
            {
                y = (A[i][p])*(B[p][j]);
                x = x+y;
            }
            D[i][j]=x;
        }
    }
      matrix_print(D,rows_D,colums_D);
}

void sort_A(int** A, int rows_A, int colums_A)
{
    int min;
    int x;

    for(int i=0;i<rows_A;i++)
    {
        for(int j=0;j<colums_A;j++)
        {
            if(j<8)
            {
                   if(A[i][j]>A[i][j+1])
                {
                    min = A[i][j+1];
                    x = A[i][j];
                    A[i][j] = min;
                    A[i][j+1] = x;

                    min = A[0][0];
                    i = 0;
                    j = 0;
                }
            }
            else
            {
                if(i*j<8*8)
            {
                   if(A[i][j]>A[i+1][0])
                {
                    min = A[i+1][0];
                    x = A[i][j];
                    A[i][j] = min;
                    A[i+1][0] = x;
                    min = A[0][0];
                    i = 0;
                    j = 0;
                }
            }
            }
        }
    }
    if(A[0][0]>A[0][1])
    {
       for(int i=0;i<rows_A;i++)
    {
        for(int j=0;j<colums_A;j++)
        {
            if(j<8)
            {
                   if(A[i][j]>A[i][j+1])
                {
                    min = A[i][j+1];
                    x = A[i][j];
                    A[i][j] = min;
                    A[i][j+1] = x;

                    min = A[0][0];
                    i = 0;
                    j = 0;
                }
            }
            else
            {
                if(i*j<8*8)
            {
                   if(A[i][j]>A[i+1][0])
                {
                    min = A[i+1][0];
                    x = A[i][j];
                    A[i][j] = min;
                    A[i+1][0] = x;
                    min = A[0][0];
                    i = 0;
                    j = 0;
                }
            }
            }
        }
    }
    }
     matrix_print(A,rows_A,colums_A);
}

void sum_rows_A_and_colums_B(int ** A, int rows_A, int colums_A, int ** B, int rows_B, int colums_B)
{
    int sum_rows;
    int sum_colums;
    sum_rows = 0;
    sum_colums = 0;
for(int i=0;i<rows_A;i++)
    {
        for(int j=0;j<colums_A;j++)
        {
             sum_rows = sum_rows + A[i][j];
        }
         printf("%d rows_A:  %d  ",i+1 ,sum_rows);
         sum_rows = 0;
         printf("\n");
    }
    printf("\n\n");
    for(int j=0;j<colums_B;j++)
    {
        for(int i=0;i<rows_B;i++)
        {
             sum_colums = sum_colums + B[i][j];
        }
         printf("%d colums_B:  %d  ",j+1 ,sum_colums);
         sum_colums = 0;
         printf("\n");
    }
}

void mamory_alocate_matrics_A(int **A,int rows_A, int colums_A)
{
     A = (int **) calloc (rows_A, sizeof (int *));
     if( A == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i = 0; i < rows_A; i++)
    {
        A[i] = (int *) calloc (colums_A, sizeof (int));
        if(A[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
}
