$NetBSD: patch-s2s_out.c,v 1.4 2012/08/26 18:25:47 adam Exp $

Non-void function must return a value.

--- s2s/out.c.orig	2012-05-12 05:21:36.000000000 +0000
+++ s2s/out.c
@@ -627,7 +627,7 @@ int out_packet(s2s_t s2s, pkt_t pkt) {
             nad_free(pkt->nad);
         free(pkt);
 
-        return;
+        return -1;
     }
 
     /* new route key */
