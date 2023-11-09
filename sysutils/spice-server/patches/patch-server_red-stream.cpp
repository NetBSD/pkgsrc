$NetBSD: patch-server_red-stream.cpp,v 1.1 2023/11/09 12:15:50 adam Exp $

TCP_CORK is missing on NetBSD, so disable it (like on win32).

--- server/red-stream.cpp.orig	2023-11-09 12:05:42.873043129 +0000
+++ server/red-stream.cpp
@@ -106,7 +106,7 @@ struct RedStreamPrivate {
     SpiceCoreInterfaceInternal *core;
 };
 
-#ifndef _WIN32
+#if !defined(_WIN32) && !defined(__NetBSD__)
 /**
  * Set TCP_CORK on socket
  */
