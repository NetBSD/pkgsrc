$NetBSD: patch-src_assuan-socket.c,v 1.1 2023/11/15 16:12:05 nia Exp $

Add missing header for select(2). Fixes build on Mac OS X 10.4.

--- src/assuan-socket.c.orig	2023-06-16 08:33:14.000000000 +0000
+++ src/assuan-socket.c
@@ -34,6 +34,7 @@
 #endif
 #else
 # include <sys/types.h>
+# include <sys/select.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 # include <arpa/inet.h>
