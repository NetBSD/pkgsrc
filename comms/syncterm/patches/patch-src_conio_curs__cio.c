$NetBSD: patch-src_conio_curs__cio.c,v 1.1 2026/05/10 06:06:45 vins Exp $

Required for FIONREAD on SunOS.

--- src/conio/curs_cio.c.orig	2026-05-10 05:58:30.211860613 +0000
+++ src/conio/curs_cio.c
@@ -21,6 +21,9 @@
 #include <locale.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
