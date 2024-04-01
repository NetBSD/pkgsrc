$NetBSD: patch-libquadmath_printf_quadmath-printf.c,v 1.2 2024/04/01 14:33:58 js Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95178

--- libquadmath/printf/quadmath-printf.c.orig	2023-07-07 07:08:21.000000000 +0000
+++ libquadmath/printf/quadmath-printf.c
@@ -22,6 +22,7 @@ Boston, MA 02110-1301, USA.  */
 #include <stdarg.h>
 #include <string.h>
 #include <stdio.h>
+#include <unistd.h>
 #include "quadmath-printf.h"
 
 /* Read a simple integer from a string and update the string pointer.
@@ -189,7 +190,7 @@ quadmath_snprintf (char *str, size_t siz
       ++format;
       info.width = va_arg (ap, int);
     }
-  else if (isdigit (*format))
+  else if (isdigit ((unsigned char) *format))
     /* Constant width specification.  */
     info.width = read_int (&format);
 
@@ -206,7 +207,7 @@ quadmath_snprintf (char *str, size_t siz
 
 	  info.prec = va_arg (ap, int);
 	}
-      else if (isdigit (*format))
+      else if (isdigit ((unsigned char) *format))
 	info.prec = read_int (&format);
       else
 	/* "%.?" is treated like "%.0?".  */
