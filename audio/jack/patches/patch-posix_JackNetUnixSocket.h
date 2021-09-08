$NetBSD: patch-posix_JackNetUnixSocket.h,v 1.1 2021/09/08 19:19:20 nia Exp $

Add NetBSD support.

--- posix/JackNetUnixSocket.h.orig	2021-07-15 06:18:26.000000000 +0000
+++ posix/JackNetUnixSocket.h
@@ -47,7 +47,7 @@ namespace Jack
 
             struct sockaddr_in fSendAddr;
             struct sockaddr_in fRecvAddr;
-        #if defined(__sun__) || defined(sun)
+        #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
             int WaitRead();
             int WaitWrite();
         #endif
