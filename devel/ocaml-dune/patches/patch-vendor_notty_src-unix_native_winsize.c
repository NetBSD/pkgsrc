$NetBSD: patch-vendor_notty_src-unix_native_winsize.c,v 1.2 2025/07/11 11:55:37 jperkin Exp $

SunOS build fix.

--- vendor/notty/src-unix/native/winsize.c.orig	2023-10-09 11:08:29.000000000 +0000
+++ vendor/notty/src-unix/native/winsize.c
@@ -3,6 +3,11 @@
 #ifdef _WIN32
 #include <caml/fail.h>
 #else
+#ifdef __sun
+#include <sys/termios.h>
+#include <unistd.h>
+#include <stropts.h>
+#endif
 #include <sys/ioctl.h>
 #include <signal.h>
 #endif
