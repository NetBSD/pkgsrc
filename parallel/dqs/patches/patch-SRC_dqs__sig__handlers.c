$NetBSD: patch-SRC_dqs__sig__handlers.c,v 1.1 2013/03/28 21:37:23 joerg Exp $

--- SRC/dqs_sig_handlers.c.orig	2013-03-28 16:19:11.000000000 +0000
+++ SRC/dqs_sig_handlers.c
@@ -351,7 +351,7 @@ void dqs_reap()
 }
 
 /************************************************************************************/
-int dqs_reap_children()
+void dqs_reap_children(void)
      
      /* 
 	several things have to be done here
