$NetBSD: patch-libiberty_vsnprintf.c,v 1.1 2016/09/06 13:57:02 maya Exp $

use stdarg, not VA_* macros.
cherry picked necessary parts from
https://gcc.gnu.org/viewcvs/gcc?view=revision&revision=206881

fixes PR pkg/50042

--- libiberty/vsnprintf.c.orig	2011-02-03 07:23:20.000000000 +0000
+++ libiberty/vsnprintf.c
@@ -95,12 +95,10 @@ static int ATTRIBUTE_PRINTF_3
 checkit (char *s, size_t n, const char *format, ...)
 {
   int result;
-  VA_OPEN (ap, format);
-  VA_FIXEDARG (ap, char *, s);
-  VA_FIXEDARG (ap, size_t, n);
-  VA_FIXEDARG (ap, const char *, format);
+  va_list ap;
+  va_start (ap, format);
   result = vsnprintf (s, n, format, ap);
-  VA_CLOSE (ap);
+  va_end (ap);
   return result;
 }
 
