#include <iostream>
#include <fstream>

using namespace std;

    void printGrid(int grid[9][9]) 
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    void readText(int grid[9][9])
    {
        ifstream in;
        in.open("C:\\Users\\sidd.bhattacharjo\\Desktop\\sudoku.txt");
        if (!in)                  
        {
            cout << "Error opening file\n";
            system("pause");
            
        }
        else
        {

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    int n = in.get();
                    if (isdigit(n)) 
                    {
                        grid[i][j] = n - '0';
                    }

                }

            }
        }
        in.close();
    }

    void findPos(int grid[9][9], int i, int j, int numPos[10])
    {
        bool pos[10] = { false };

        //check row
        for (int row = 0; row < 9; row++)
        {
            if (grid[row][j] != 0)pos[grid[row][j]] = true;
        }

        //check col
        for (int col = 0; col < 9; col++)
        {
            if (grid[i][col] != 0)pos[grid[i][col]] = true;
        }

        //check box
        for (int row = i / 3 * 3; row < (i / 3 * 3) + 3; row++)
        {
            for (int col = j / 3 * 3; col < (j / 3 * 3) + 3; col++)
            {
                if (grid[row][col] != 0)pos[grid[row][col]] = true;
            }
        }

        for (int i = 1; i < 10; i++)
        {
            if (!pos[i])numPos[i] = i;
            
        }
       
    }

    bool isDone(int grid[9][9])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 0)return false;
            }
           
        }

        return true;

    }

    void solveGrid(int grid[9][9])
    {
        if (isDone(grid))return;
        int numPos[10] = { 0 };
        int x = 0;
        int y = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j] == 0)
                {
                    x = i;
                    y = j;
                    
                    findPos(grid, i, j, numPos);
                    break;
                }
                
            }
            break;
        }

        for (int i = 1; i < 10; i++)
        {
            if (numPos[i] != 0)
            {
                grid[x][y] = numPos[i];
                solveGrid(grid);
            }

        }

        grid[x][y] = 0;
        return;
    }

    int main(void)
    {
        int numPos[10] = { 0 };
        int grid[9][9] = { 0 };
        readText(grid);
        printGrid(grid);
        solveGrid(grid);
        printGrid(grid);
        system("pause");
        return 0;
    }

    

