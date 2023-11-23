$NetBSD: patch-perf_cairo-perf-print.c,v 1.1 2023/11/23 10:57:44 jperkin Exp $

SunOS needs sys/termios.h for TIOCGWINSZ.

--- perf/cairo-perf-print.c.orig	2023-11-23 10:44:50.499929610 +0000
+++ perf/cairo-perf-print.c
@@ -43,6 +43,9 @@
 #if USE_TERMINAL_SIZE
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/termios.h>
+#endif
 #endif
 
 static void
