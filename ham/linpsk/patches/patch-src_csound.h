$NetBSD: patch-src_csound.h,v 1.1 2014/09/25 12:29:35 jperkin Exp $

SunOS needs sys/termios.h

--- src/csound.h.orig	2005-02-04 15:28:23.000000000 +0000
+++ src/csound.h
@@ -17,6 +17,10 @@
 #ifndef CSOUND_H
 #define CSOUND_H
 
+#ifdef __sun
+#include <sys/termios.h>
+#endif
+
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <fcntl.h>
