$NetBSD: patch-platform_PSerial__unix.cpp,v 1.1 2017/07/05 20:23:39 wiedi Exp $

Adjust macro for all SunOS
--- platform/PSerial_unix.cpp.orig	2001-04-16 00:56:29.000000000 +0000
+++ platform/PSerial_unix.cpp
@@ -31,7 +31,7 @@
 #include <termios.h>
 
 // need another #include for Solaris - Richard Mitchell <gpsphoto@designprofessionals.com>
-#ifdef SOLARIS
+#if defined(__sun)
 #include <sys/filio.h>
 #endif
 
