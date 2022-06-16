$NetBSD: patch-libquadmath_printf_quadmath-printf.c,v 1.1 2022/06/16 15:43:55 adam Exp $

Fix -Werror=char-subscripts.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=95178

--- libquadmath/printf/quadmath-printf.c.orig	2020-05-07 10:50:02.000000000 +0000
+++ libquadmath/printf/quadmath-printf.c
@@ -189,7 +189,7 @@ quadmath_snprintf (char *str, size_t siz
       ++format;
       info.width = va_arg (ap, int);
     }
-  else if (isdigit (*format))
+  else if (isdigit ((unsigned char) *format))
     /* Constant width specification.  */
     info.width = read_int (&format);
 
@@ -206,7 +206,7 @@ quadmath_snprintf (char *str, size_t siz
 
 	  info.prec = va_arg (ap, int);
 	}
-      else if (isdigit (*format))
+      else if (isdigit ((unsigned char) *format))
 	info.prec = read_int (&format);
       else
 	/* "%.?" is treated like "%.0?".  */
