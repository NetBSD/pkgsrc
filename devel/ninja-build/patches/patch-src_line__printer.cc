$NetBSD: patch-src_line__printer.cc,v 1.1 2014/09/16 08:44:25 jperkin Exp $

SunOS needs sys/termios.h

--- src/line_printer.cc.orig	2014-06-27 23:37:05.000000000 +0000
+++ src/line_printer.cc
@@ -21,6 +21,9 @@
 #else
 #include <unistd.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/termios.h>
+#endif
 #include <sys/time.h>
 #endif
 
