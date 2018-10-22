$NetBSD: patch-iftop.c,v 1.2 2018/10/22 14:58:14 jperkin Exp $

Support DLT_PPP_SERIAL.

--- iftop.c.orig	2014-01-19 20:21:19.000000000 +0000
+++ iftop.c
@@ -757,6 +757,12 @@ void packet_init() {
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
