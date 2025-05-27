$NetBSD: patch-config.c,v 1.1 2025/05/27 19:15:12 vins Exp $

stdarg.h required for va_* macros.

--- config.c.orig	2024-08-13 10:49:48.000000000 +0000
+++ config.c
@@ -8,6 +8,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdarg.h>
 #include <ctype.h>
 #include <pwd.h>
 #include <unistd.h>
