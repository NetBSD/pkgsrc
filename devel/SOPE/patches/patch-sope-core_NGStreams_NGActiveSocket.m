$NetBSD: patch-sope-core_NGStreams_NGActiveSocket.m,v 1.1 2016/12/15 23:57:16 wiedi Exp $

ignore MSG_NOSIGNAL on sunos
--- sope-core/NGStreams/NGActiveSocket.m.orig	2016-08-17 12:26:04.000000000 +0000
+++ sope-core/NGStreams/NGActiveSocket.m
@@ -54,6 +54,10 @@
 #  include <sys/ioctl.h>
 #endif
 
+#if defined(__sun)
+#  define MSG_NOSIGNAL 0
+#endif
+
 #if HAVE_WINDOWS_H && !defined(__CYGWIN32__)
 #  include <windows.h>
 #endif
