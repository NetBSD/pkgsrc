$NetBSD: patch-common_packets.c,v 1.1 2012/07/31 15:49:37 prlw1 Exp $

Fixes part 1 of http://secunia.com/advisories/40476/
c.f. https://gna.org/bugs/?20003

--- common/packets.c.orig	2012-03-31 12:35:45.000000000 +0000
+++ common/packets.c
@@ -331,7 +331,7 @@ instead of just testing if the returning
 return a NULL packet even if everything is OK (receive_packet_goto_route).
 **************************************************************************/
 void *get_packet_from_connection(struct connection *pc,
-				 enum packet_type *ptype, bool * presult)
+				 enum packet_type *ptype, bool *presult)
 {
   int len_read;
   int whole_packet_len;
@@ -386,6 +386,14 @@ void *get_packet_from_connection(struct 
     return NULL;		/* not all data has been read */
   }
 
+  if (whole_packet_len < header_size) {
+    log_verbose("The packet size is reported to be less than header alone. "
+                "The connection will be closed now.");
+    connection_close(pc, _("illegal packet size"));
+
+    return NULL;
+  }
+
 #ifdef USE_COMPRESSION
   if (compressed_packet) {
     uLong compressed_size = whole_packet_len - header_size;
