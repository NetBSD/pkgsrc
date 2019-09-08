$NetBSD: patch-src_libcec_platform_posix_serialport.cpp,v 1.1 2019/09/08 12:30:54 nia Exp $

Support NetBSD.

--- src/libcec/platform/posix/serialport.cpp.orig	2018-12-21 21:34:45.000000000 +0000
+++ src/libcec/platform/posix/serialport.cpp
@@ -38,7 +38,7 @@
 #include "../util/baudrate.h"
 #include "p8-platform/posix/os-socket.h"
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #ifndef XCASE
 #define XCASE	0
 #endif
