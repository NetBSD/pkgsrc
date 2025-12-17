$NetBSD: patch-bcc_dbprintf.c,v 1.1 2025/12/17 10:55:53 prlw1 Exp $

Fix build: implicit declaration of function:
- 'vdbprintf'
- 'write'
- 'strlen'

--- bcc/dbprintf.c.orig	2014-03-14 04:33:19.000000000 +0000
+++ bcc/dbprintf.c
@@ -1,6 +1,7 @@
-
 #include <sys/types.h>
 #include <fcntl.h>
+#include <string.h>
+#include <unistd.h>
 
 #if defined(__STDC__) && !defined(__FIRST_ARG_IN_AX__)
 #include <stdarg.h>
@@ -10,6 +11,8 @@
 #define va_strt(p,i) va_start(p)
 #endif
 
+int vdbprintf(register __const char *, register va_list);
+
 #if defined(__STDC__) && !defined(__FIRST_ARG_IN_AX__)
 int dbprintf(const char * fmt, ...)
 #else
