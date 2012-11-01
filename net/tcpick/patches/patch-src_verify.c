$NetBSD: patch-src_verify.c,v 1.1 2012/11/01 19:35:20 joerg Exp $

--- src/verify.c.orig	2012-10-30 21:54:01.000000000 +0000
+++ src/verify.c
@@ -92,7 +92,7 @@
  tcppacket->rst         == 1
 
 
-__inline__ int
+int
 established_packet ( struct CONN * conn_ptr, struct HOST_DESC * Desc)
 /* called by verify()
    packets of established connections come here */
@@ -121,7 +121,7 @@ established_packet ( struct CONN * conn_
 
 }
 
-__inline__ int  
+int  
 verify()
 /* called by got_packet().
    this is the engine that matches the packets with their connection */
