$NetBSD: patch-ppp_defs.c,v 1.1 2011/11/27 19:50:23 joerg Exp $

--- ppp/defs.c.orig	2011-11-26 23:30:34.000000000 +0000
+++ ppp/defs.c
@@ -28,6 +28,7 @@
 
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
