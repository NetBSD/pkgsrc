$NetBSD: patch-source_shared__lib_sources_platform_posix_socket.cpp,v 1.1 2019/09/08 20:54:16 nia Exp $

Support NetBSD.

--- source/shared_lib/sources/platform/posix/socket.cpp.orig	2017-03-08 20:39:12.000000000 +0000
+++ source/shared_lib/sources/platform/posix/socket.cpp
@@ -319,7 +319,7 @@ string Ip::getString() const{
 //	class Socket
 // ===============================================
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(BSD) || defined(__APPLE__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(BSD) || defined(__APPLE__) || defined(__linux__)
 # define USE_GETIFADDRS 1
 # include <ifaddrs.h>
 #endif
