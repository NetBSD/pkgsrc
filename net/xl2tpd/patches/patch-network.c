$NetBSD: patch-network.c,v 1.5 2017/10/13 17:24:05 christos Exp $

Argument to setsockopt should be int not long

--- network.c.orig	2017-08-02 13:46:06.000000000 -0400
+++ network.c	2017-10-13 13:09:05.187604385 -0400
@@ -39,7 +39,7 @@
 
 int init_network (void)
 {
-    long arg;
+    int arg;
     unsigned int length = sizeof (server);
     gethostname (hostname, sizeof (hostname));
     server.sin_family = AF_INET;
