$NetBSD: patch-server_red-stream.c,v 1.3 2021/01/05 15:14:39 jperkin Exp $

Fix build on SunOS.
No TCP_CORK on netbsd. Disable (like win32)

--- server/red-stream.c.orig	2020-02-27 11:26:12.000000000 +0000
+++ server/red-stream.c
@@ -17,6 +17,15 @@
 */
 #include <config.h>
 
+#if defined(__sun)
+#define MSG_NOSIGNAL	0
+#  if __STDC_VERSION__ - 0 < 199901L
+#define _XOPEN_SOURCE	500
+#  else
+#define _XOPEN_SOURCE	600
+#  endif
+#endif
+
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -105,7 +114,7 @@ struct RedStreamPrivate {
     SpiceCoreInterfaceInternal *core;
 };
 
-#ifndef _WIN32
+#if !defined(_WIN32) && !defined(__NetBSD__)
 /**
  * Set TCP_CORK on socket
  */
