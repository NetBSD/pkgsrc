/*
 * Public domain version of ffsll by Niclas Rosenvik
 * used here for platforms that miss a system ffsll.
 */

#include <sys/types.h>

int
ffsll(long long int v)
{
size_t llbits = sizeof(long long int) * 8;
long long unsigned int comp_mask = 1;

for (size_t i=0; i < llbits; ++i)
{
  if (v & comp_mask) {
    return (i+1);
  }
  comp_mask <<= 1;
}

return 0;
}
