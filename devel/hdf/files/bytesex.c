#include <stdio.h>

union {long Long;
  char Char[sizeof(long)];
} u;

int
main()
{
  u.Long = 1;
  if (u.Char[0] == 1)                       /* little-endian */
    printf("-DSWAP\n");
  else if (u.Char[sizeof(long) - 1] == 1)   /* big-endian */
    printf("\n");
  else exit(1);
  return 0;
}
