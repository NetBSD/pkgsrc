$NetBSD: patch-lib_libucsi_dvb_cell__frequency__link__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/cell_frequency_link_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/cell_frequency_link_descriptor.h
@@ -78,8 +78,8 @@ static inline struct dvb_cell_frequency_
 		if ((pos + sizeof(struct dvb_cell_frequency_link_cell)) > len)
 			return NULL;
 
-		bswap16(buf+pos);
-		bswap32(buf+pos+2);
+		ubswap16(buf+pos);
+		ubswap32(buf+pos+2);
 
 		pos += sizeof(struct dvb_cell_frequency_link_cell);
 
@@ -91,7 +91,7 @@ static inline struct dvb_cell_frequency_
 
 		pos2 = 0;
 		while(pos2 < e->subcell_loop_info_length) {
-			bswap32(buf+pos+pos2+1);
+			ubswap32(buf+pos+pos2+1);
 
 			pos2 += sizeof(struct dvb_cell_frequency_link_cell_subcell);
 		}
