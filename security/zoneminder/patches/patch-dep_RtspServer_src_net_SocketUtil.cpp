$NetBSD: patch-dep_RtspServer_src_net_SocketUtil.cpp,v 1.1 2024/12/01 13:49:47 gdt Exp $

Add NetBSD to BSD conditional.

\todo File upstream PR.

--- dep/RtspServer/src/net/SocketUtil.cpp.orig	2024-01-14 21:17:15.225438102 +0000
+++ dep/RtspServer/src/net/SocketUtil.cpp
@@ -23,7 +23,7 @@ bool SocketUtil::Bind(SOCKET sockfd, std
 
 void SocketUtil::SetNonBlock(SOCKET fd)
 {
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     int flags = fcntl(fd, F_GETFL, 0);
     fcntl(fd, F_SETFL, flags | O_NONBLOCK);
 #elif defined(WIN32) || defined(_WIN32)
@@ -34,7 +34,7 @@ void SocketUtil::SetNonBlock(SOCKET fd)
 
 void SocketUtil::SetBlock(SOCKET fd, int write_timeout)
 {
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     int flags = fcntl(fd, F_GETFL, 0);
     fcntl(fd, F_SETFL, flags&(~O_NONBLOCK));
 #elif defined(WIN32) || defined(_WIN32)
@@ -45,7 +45,7 @@ void SocketUtil::SetBlock(SOCKET fd, int
     if(write_timeout > 0)
     {
 #ifdef SO_SNDTIMEO
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     struct timeval tv = {write_timeout/1000, (write_timeout%1000)*1000};
     setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, (char*)&tv, sizeof tv);
 #elif defined(WIN32) || defined(_WIN32)
@@ -168,7 +168,7 @@ int SocketUtil::GetPeerAddr(SOCKET sockf
 
 void SocketUtil::Close(SOCKET sockfd)
 {
-#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux) || defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     ::close(sockfd);
 #elif defined(WIN32) || defined(_WIN32)
     ::closesocket(sockfd);
