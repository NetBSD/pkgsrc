$NetBSD: patch-src_packet__manip.h,v 1.1 2012/11/19 03:06:04 joerg Exp $

--- src/packet_manip.h.orig	2012-11-19 00:55:44.000000000 +0000
+++ src/packet_manip.h
@@ -67,18 +67,18 @@ typedef struct packet
 } packet_t;
 
 
-inline int       look_packet_bytes(u_int8_t *, packet_t *, unsigned int);
-inline int       get_packet_bytes(u_int8_t *, packet_t *, unsigned int);
-inline int       get_packet_bytestoend(u_int8_t *, packet_t *, unsigned int);
-inline int       get_packet_line(u_int8_t *, u_int32_t, packet_t *);
-inline int       get_packet_string(u_int8_t *, u_int32_t, packet_t *);
-inline int       skip_packet_bytes(packet_t *, unsigned int);
-inline int       skip_packet_toapparentend(packet_t *);
-inline u_int32_t get_packet_bytesleft(packet_t *);
-inline u_int32_t get_packet_apparentbytesleft(packet_t *);
-inline void      set_packet_mark(packet_t *);
-inline int32_t   get_packet_markdistance(packet_t *);
-inline void      set_packet_apparentend(packet_t *, int);
-inline int       packet_haspadding(packet_t *);
+int       look_packet_bytes(u_int8_t *, packet_t *, unsigned int);
+int       get_packet_bytes(u_int8_t *, packet_t *, unsigned int);
+int       get_packet_bytestoend(u_int8_t *, packet_t *, unsigned int);
+int       get_packet_line(u_int8_t *, u_int32_t, packet_t *);
+int       get_packet_string(u_int8_t *, u_int32_t, packet_t *);
+int       skip_packet_bytes(packet_t *, unsigned int);
+int       skip_packet_toapparentend(packet_t *);
+u_int32_t get_packet_bytesleft(packet_t *);
+u_int32_t get_packet_apparentbytesleft(packet_t *);
+void      set_packet_mark(packet_t *);
+int32_t   get_packet_markdistance(packet_t *);
+void      set_packet_apparentend(packet_t *, int);
+int       packet_haspadding(packet_t *);
 
 #endif
