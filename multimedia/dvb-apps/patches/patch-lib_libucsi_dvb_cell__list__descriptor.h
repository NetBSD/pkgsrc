$NetBSD: patch-lib_libucsi_dvb_cell__list__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/cell_list_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/cell_list_descriptor.h
@@ -84,10 +84,10 @@ static inline struct dvb_cell_list_descr
 		if ((pos + sizeof(struct dvb_cell_list_entry)) > len)
 			return NULL;
 
-		bswap16(buf+pos);
-		bswap16(buf+pos+2);
-		bswap16(buf+pos+4);
-		bswap32(buf+pos+6);
+		ubswap16(buf+pos);
+		ubswap16(buf+pos+2);
+		ubswap16(buf+pos+4);
+		ubswap32(buf+pos+6);
 
 		pos += sizeof(struct dvb_cell_list_entry);
 
@@ -99,9 +99,9 @@ static inline struct dvb_cell_list_descr
 
 		pos2 = 0;
 		while(pos2 < e->subcell_info_loop_length) {
-			bswap16(buf+pos+pos2+1);
-			bswap16(buf+pos+pos2+3);
-			bswap24(buf+pos+pos2+5);
+			ubswap16(buf+pos+pos2+1);
+			ubswap16(buf+pos+pos2+3);
+			ubswap24(buf+pos+pos2+5);
 
 			pos2 += sizeof(struct dvb_subcell_list_entry);
 		}
