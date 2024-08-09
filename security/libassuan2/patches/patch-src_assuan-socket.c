$NetBSD: patch-src_assuan-socket.c,v 1.2 2024/08/09 03:53:22 ryoon Exp $

Add missing header for select(2). Fixes build on Mac OS X 10.4.

--- src/assuan-socket.c.orig	2024-06-27 04:17:34.537130917 +0000
+++ src/assuan-socket.c
@@ -32,6 +32,7 @@
 # include <io.h>
 #else
 # include <sys/types.h>
+# include <sys/select.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 # include <arpa/inet.h>
