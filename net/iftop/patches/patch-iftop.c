$NetBSD: patch-iftop.c,v 1.1 2017/12/11 10:44:17 manu Exp $

--- iftop.c.orig	2014-01-19 21:21:19.000000000 +0100
+++ iftop.c	2017-12-11 11:22:55.000000000 +0100
@@ -756,8 +756,14 @@
     }
     else if(dlt == DLT_PPP) {
         packet_handler = handle_ppp_packet;
     }
+#ifdef DLT_PPP_SERIAL
+    else if(dlt == DLT_PPP_SERIAL) {
+        packet_handler = handle_ppp_packet;
+    }
+
+#endif
 /* 
  * SLL support not available in older libpcaps
  */
 #ifdef DLT_LINUX_SLL
