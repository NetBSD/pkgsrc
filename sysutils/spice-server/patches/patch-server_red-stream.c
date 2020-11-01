$NetBSD: patch-server_red-stream.c,v 1.2 2020/11/01 19:36:37 maya Exp $

No TCP_CORK on netbsd. Disable (like win32)

--- server/red-stream.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/red-stream.c
@@ -105,7 +105,7 @@ struct RedStreamPrivate {
     SpiceCoreInterfaceInternal *core;
 };
 
-#ifndef _WIN32
+#if !defined(_WIN32) && !defined(__NetBSD__)
 /**
  * Set TCP_CORK on socket
  */
