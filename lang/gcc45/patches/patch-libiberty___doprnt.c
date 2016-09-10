$NetBSD: patch-libiberty___doprnt.c,v 1.1 2016/09/10 13:59:31 maya Exp $

use stdarg, not VA_* macros.
cherry picked necessary parts from
https://gcc.gnu.org/viewcvs/gcc?view=revision&revision=206881

fixes PR pkg/50042

--- libiberty/_doprnt.c.orig	2005-05-10 15:33:18.000000000 +0000
+++ libiberty/_doprnt.c
@@ -222,11 +222,11 @@ static int
 checkit (const char* format, ...)
 {
   int result;
-  VA_OPEN (args, format);
-  VA_FIXEDARG (args, char *, format);
+  va_list args;
+  va_start (args, format);
 
   result = _doprnt (format, args, stdout);
-  VA_CLOSE (args);
+  va_end (args);
 
   return result;
 }
