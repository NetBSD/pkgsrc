$NetBSD: patch-udp.c,v 1.1 2013/09/20 23:07:44 joerg Exp $

--- udp.c.orig	2003-06-10 16:41:29.000000000 +0000
+++ udp.c
@@ -561,7 +561,7 @@ void
 udp_report (struct transport *t)
 {
   struct udp_transport *u = (struct udp_transport *)t;
-  char *src, *dst;
+  char *src = NULL, *dst = NULL;
 
   if (sockaddr2text (u->src, &src, 0))
     goto ret;
