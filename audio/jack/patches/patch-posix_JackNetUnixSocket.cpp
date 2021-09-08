$NetBSD: patch-posix_JackNetUnixSocket.cpp,v 1.1 2021/09/08 19:19:20 nia Exp $

Add NetBSD support.

--- posix/JackNetUnixSocket.cpp.orig	2021-07-15 06:18:26.000000000 +0000
+++ posix/JackNetUnixSocket.cpp
@@ -280,7 +280,7 @@ namespace Jack
 
     //timeout************************************************************************************************************
 
-#if defined(__sun__) || defined(sun)
+#if defined(__sun__) || defined(sun) || defined(__NetBSD__)
     int JackNetUnixSocket::SetTimeOut(int us)
     {
         int	flags;
@@ -389,7 +389,7 @@ namespace Jack
     //network operations**************************************************************************************************
     int JackNetUnixSocket::SendTo(const void* buffer, size_t nbytes, int flags)
     {
-    #if defined(__sun__) || defined(sun)
+    #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
         if (WaitWrite() < 0) {
             return -1;
         }
@@ -408,7 +408,7 @@ namespace Jack
             return addr_conv;
         }
         fSendAddr.sin_port = htons(fPort);
-    #if defined(__sun__) || defined(sun)
+    #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
         if (WaitWrite() < 0) {
             return -1;
         }
@@ -418,7 +418,7 @@ namespace Jack
 
     int JackNetUnixSocket::Send(const void* buffer, size_t nbytes, int flags)
     {
-    #if defined(__sun__) || defined(sun)
+    #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
         if (WaitWrite() < 0) {
             return -1;
         }
@@ -433,7 +433,7 @@ namespace Jack
     int JackNetUnixSocket::RecvFrom(void* buffer, size_t nbytes, int flags)
     {
         socklen_t addr_len = sizeof(socket_address_t);
-    #if defined(__sun__) || defined(sun)
+    #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
         if (WaitRead() < 0) {
             return -1;
         }
@@ -447,7 +447,7 @@ namespace Jack
 
     int JackNetUnixSocket::Recv(void* buffer, size_t nbytes, int flags)
     {
-    #if defined(__sun__) || defined(sun)
+    #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
         if (WaitRead() < 0) {
             return -1;
         }
@@ -462,7 +462,7 @@ namespace Jack
     int JackNetUnixSocket::CatchHost(void* buffer, size_t nbytes, int flags)
     {
         socklen_t addr_len = sizeof(socket_address_t);
-    #if defined(__sun__) || defined(sun)
+    #if defined(__sun__) || defined(sun) || defined(__NetBSD__)
         if (WaitRead() < 0) {
             return -1;
         }
