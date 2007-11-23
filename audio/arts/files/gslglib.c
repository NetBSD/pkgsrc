#include "gslglib.h"

#include <stdio.h>

void
gsl_g_log (const gchar*msg,const char *format, va_list ap)
{
  if (msg) printf ("\n%s",msg);
  vprintf(format, ap);
  if (msg) printf ("\n");
}

void
gsl_g_print_fd (int fd, const char *format, va_list ap)
{
    g_return_if_fail (fd == 1 || fd == 2);
    if (fd == 1)
       vprintf (format, ap);
     else
       vfprintf (stderr, format, ap);
}


