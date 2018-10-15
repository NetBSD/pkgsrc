$NetBSD: patch-Source_Core_Core_IOS_Network_Socket.h,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Core/IOS/Network/Socket.h.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Core/IOS/Network/Socket.h
@@ -15,7 +15,8 @@ typedef pollfd pollfd_t;
 #define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
 #define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
 
-#elif defined(__linux__) or defined(__APPLE__) or defined(__FreeBSD__) or defined(__HAIKU__)
+#elif defined(__linux__) or defined(__APPLE__) or defined(__FreeBSD__) or defined(__NetBSD__) \
+   or defined(__HAIKU__)
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <sys/ioctl.h>
