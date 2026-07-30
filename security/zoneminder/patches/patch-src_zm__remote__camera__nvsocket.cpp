$NetBSD: patch-src_zm__remote__camera__nvsocket.cpp,v 1.1 2026/07/30 12:36:00 gdt Exp $

Add missing include on NetBSD.

\todo File upstream.

--- src/zm_remote_camera_nvsocket.cpp.orig	2026-07-26 00:42:57.983592814 +0000
+++ src/zm_remote_camera_nvsocket.cpp
@@ -32,6 +32,9 @@
 #ifdef __FreeBSD__
 #include <netinet/in.h>
 #endif
+#ifdef __NetBSD__
+#include <netinet/in.h>
+#endif
 
 RemoteCameraNVSocket::RemoteCameraNVSocket(
   const Monitor *monitor,
