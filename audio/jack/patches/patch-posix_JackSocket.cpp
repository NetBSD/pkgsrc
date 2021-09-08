$NetBSD: patch-posix_JackSocket.cpp,v 1.1 2021/09/08 19:19:20 nia Exp $

Add NetBSD support.

--- posix/JackSocket.cpp.orig	2021-07-15 06:18:26.000000000 +0000
+++ posix/JackSocket.cpp
@@ -51,7 +51,7 @@ JackClientSocket::JackClientSocket(): Ja
 JackClientSocket::JackClientSocket(int socket): JackClientRequestInterface(), fSocket(socket),fTimeOut(0), fPromiscuous(false), fPromiscuousGid(-1)
 {}
 
-#if defined(__sun__) || defined(sun)
+#if defined(__sun__) || defined(sun) || defined(__NetBSD__)
 
 void JackClientSocket::SetReadTimeOut(long sec)
 {
@@ -168,7 +168,7 @@ int JackClientSocket::Read(void* data, i
 {
     int res;
 
-#if defined(__sun__) || defined(sun)
+#if defined(__sun__) || defined(sun) || defined(__NetBSD__)
     if (fTimeOut > 0) {
 
         struct timeval tv;
@@ -214,7 +214,7 @@ int JackClientSocket::Write(void* data, 
 {
     int res;
 
-#if defined(__sun__) || defined(sun)
+#if defined(__sun__) || defined(sun) || defined(__NetBSD__)
     if (fTimeOut > 0) {
 
         struct timeval tv;
