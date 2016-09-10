$NetBSD: patch-libiberty_asprintf.c,v 1.1 2016/09/10 13:59:31 maya Exp $

use stdarg, not VA_* macros.
cherry picked necessary parts from
https://gcc.gnu.org/viewcvs/gcc?view=revision&revision=206881

fixes PR pkg/50042

--- libiberty/asprintf.c.orig	2005-05-10 15:33:18.000000000 +0000
+++ libiberty/asprintf.c
@@ -47,10 +47,9 @@ int
 asprintf (char **buf, const char *fmt, ...)
 {
   int status;
-  VA_OPEN (ap, fmt);
-  VA_FIXEDARG (ap, char **, buf);
-  VA_FIXEDARG (ap, const char *, fmt);
+  va_list ap;
+  va_start (ap, fmt);
   status = vasprintf (buf, fmt, ap);
-  VA_CLOSE (ap);
+  va_end (ap);
   return status;
 }
