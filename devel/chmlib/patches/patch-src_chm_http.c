$NetBSD: patch-src_chm_http.c,v 1.2 2025/12/20 12:19:03 nia Exp $

Add missing headers for inet_addr(3), close(2), write(2).

--- src/chm_http.c.orig	2009-05-23 15:08:18.000000000 +0000
+++ src/chm_http.c
@@ -33,6 +33,7 @@
 #define _REENTRANT
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string.h>
 #if __sun || __sgi
 #include <strings.h>
@@ -43,6 +44,7 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 
 /* threading includes */
 #include <pthread.h>
