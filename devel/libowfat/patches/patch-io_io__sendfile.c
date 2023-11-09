$NetBSD: patch-io_io__sendfile.c,v 1.2 2023/11/09 19:26:00 schmonz Exp $

Fix Illumos build.

--- io/io_sendfile.c.orig	2022-04-25 14:21:38.000000000 +0000
+++ io/io_sendfile.c
@@ -43,7 +43,9 @@ int64 io_sendfile(int64 out,int64 in,uin
 
 #elif defined (__sun__) && defined(__svr4__)
 
+#ifndef _LARGEFILE64_SOURCE
 #define _LARGEFILE64_SOURCE
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/sendfile.h>
