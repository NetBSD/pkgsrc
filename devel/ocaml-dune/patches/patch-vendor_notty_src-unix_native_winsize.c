$NetBSD: patch-vendor_notty_src-unix_native_winsize.c,v 1.3 2026/01/11 18:09:04 alnsn Exp $

SunOS build fix.

--- vendor/notty/src-unix/native/winsize.c.orig	2026-01-11 01:23:58.628536099 +0000
+++ vendor/notty/src-unix/native/winsize.c
@@ -3,6 +3,11 @@
 #ifdef _WIN32
 #include <windows.h>
 #else
+#ifdef __sun
+#include <sys/termios.h>
+#include <unistd.h>
+#include <stropts.h>
+#endif
 #include <sys/ioctl.h>
 #include <signal.h>
 #endif
