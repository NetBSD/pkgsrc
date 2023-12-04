$NetBSD: patch-vendor_notty_src-unix_native_winsize.c,v 1.1 2023/12/04 13:56:34 jperkin Exp $

SunOS build fix.

--- vendor/notty/src-unix/native/winsize.c.orig	2023-12-04 13:26:08.056576737 +0000
+++ vendor/notty/src-unix/native/winsize.c
@@ -3,6 +3,9 @@
 #ifdef _WIN32
 #include <caml/fail.h>
 #else
+#ifdef __sun
+#include <sys/termios.h>
+#endif
 #include <sys/ioctl.h>
 #include <signal.h>
 #endif
