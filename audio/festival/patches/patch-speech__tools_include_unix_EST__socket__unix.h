$NetBSD: patch-speech__tools_include_unix_EST__socket__unix.h,v 1.1 2012/12/18 13:27:10 jperkin Exp $

Avoid ssize_t declaration in newer Solaris.

--- ./speech_tools/include/unix/EST_socket_unix.h.orig	2012-12-18 13:04:33.464265098 +0000
+++ ./speech_tools/include/unix/EST_socket_unix.h	2012-12-18 13:07:17.081805920 +0000
@@ -45,7 +45,7 @@
 #include <errno.h>
 
 /* Solaris defines this, linux doesn't */
-#if defined(sun) && !defined(SVR4)
+#if defined(sun) && !defined(SVR4) && !defined(_SSIZE_T)
 typedef int ssize_t;
 #endif
 
