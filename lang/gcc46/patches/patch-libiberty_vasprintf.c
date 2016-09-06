$NetBSD: patch-libiberty_vasprintf.c,v 1.1 2016/09/06 13:57:02 maya Exp $

use stdarg, not VA_* macros.
cherry picked necessary parts from
https://gcc.gnu.org/viewcvs/gcc?view=revision&revision=206881

fixes PR pkg/50042

--- libiberty/vasprintf.c.orig	2011-02-03 07:23:20.000000000 +0000
+++ libiberty/vasprintf.c
@@ -165,10 +165,10 @@ static void ATTRIBUTE_PRINTF_1
 checkit (const char *format, ...)
 {
   char *result;
-  VA_OPEN (args, format);
-  VA_FIXEDARG (args, const char *, format);
+  va_list args;
+  va_start (args, format);
   vasprintf (&result, format, args);
-  VA_CLOSE (args);
+  va_end (args);
 
   if (strlen (result) < (size_t) global_total_width)
     printf ("PASS: ");
