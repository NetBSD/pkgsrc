$NetBSD: patch-mmstu.h,v 1.1 2008/09/12 14:47:39 sborrill Exp $

Fix for:
* A signedness error leading to a stack-based buffer overflow in the
mms_ReceiveCommand() function in modules/access/mms/mmstu.c
(CVE-2008-3794).

--- modules/access/mms/mmstu.h.orig	2008-07-08 21:59:23.000000000 +0100
+++ modules/access/mms/mmstu.h	2008-09-12 11:16:06.000000000 +0100
@@ -62,10 +62,10 @@
     int         i_packet_seq_num;
 
     uint8_t     *p_cmd;     /* latest command read */
-    int         i_cmd;      /* allocated at the begining */
+    size_t      i_cmd;      /* allocated at the begining */
 
     uint8_t     *p_header;  /* allocated by mms_ReadPacket */
-    int         i_header;
+    size_t      i_header;
 
     uint8_t     *p_media;   /* allocated by mms_ReadPacket */
     size_t      i_media;
@@ -86,7 +86,7 @@
     size_t      i_packet_length;
     uint32_t    i_packet_count;
     int         i_max_bit_rate;
-    int         i_header_size;
+    size_t      i_header_size;
 
     /* */
     vlc_bool_t  b_seekable;
