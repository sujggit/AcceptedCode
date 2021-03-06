/**************************************************
  Description :
  Editor      : Chirl
  EditDate    : 2017/02/27
              _ 
             /  \               
            /|oo \              
           (_|  /_)             
             `@/  \    _        
             |     \   \\       
              \||   \   ))      
              |||\ /  \//       
            _//|| _\   /          
     ______(_/(_|(____/_________ 
**************************************************/
#ifndef _8_H_
#define _8_H_

#pragma execution_character_set("utf-8")

namespace Chirl
{
    class Solution_8
    {
    public:
        Solution_8() : m_iMethodCnt(nullptr){}
        int jumpFloor(int number) 
        {
            if (nullptr == m_iMethodCnt) 
            {
                m_iMethodCnt = new int[number + 1];

                for (int i = 0; i < number + 1; i++) 
                {
                    m_iMethodCnt[i] = 0;
                }
            }

            if (2 >= number) 
            {
                m_iMethodCnt[number] = number;
                return number;
            }
            else if (0 != m_iMethodCnt[number]) 
            {
                return m_iMethodCnt[number];
            }

            m_iMethodCnt[number] = jumpFloor(number - 1) + jumpFloor(number - 2);

            return m_iMethodCnt[number];
        }

        static void test()
        {
            Solution_8 su;
            su.jumpFloor(20);
        }
    private:
        int *m_iMethodCnt;   
    };

}
namespace Wcytem
{
    class Solution_8
    {
    public:
        int jumpFloor(int number) {
            if(number == 0)
                return 0;
            else
            {
                int pre1 = 1,pre2 = 2,temp = 0;
                while(--number)
                {
                    temp = pre1;
                    pre1 = pre2;
                    pre2+= temp;
                }
                return pre1;
            }
        }

        static void test()
        {
            Solution_8 su;
            su.jumpFloor(20);
        }     
    };



}


#endif //!_8_H_