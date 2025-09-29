$NetBSD: patch-src_chm_http.c,v 1.1 2025/09/29 20:47:29 mrg Exp $

Add missing header for inet_addr(3).

--- src/chm_http.c.orig	2009-05-23 08:08:18.000000000 -0700
+++ src/chm_http.c	2025-09-25 11:57:21.415075179 -0700
@@ -43,6 +43,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 /* threading includes */
 #include <pthread.h>
