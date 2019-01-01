$NetBSD: patch-Source_Core_Core_IPC__HLE_WII__Socket.h,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Core/IPC_HLE/WII_Socket.h.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Core/IPC_HLE/WII_Socket.h
@@ -15,7 +15,7 @@ typedef pollfd pollfd_t;
 #define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
 #define FREE(x) HeapFree(GetProcessHeap(), 0, (x))
 
-#elif defined(__linux__) or defined(__APPLE__) or defined(__FreeBSD__)
+#elif defined(__linux__) or defined(__APPLE__) or defined(__FreeBSD__) or defined(__NetBSD__)
 #include <netdb.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
