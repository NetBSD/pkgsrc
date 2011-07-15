$NetBSD: patch-lib_libucsi_dvb_mosaic__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/mosaic_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/mosaic_descriptor.h
@@ -134,7 +134,7 @@ static inline struct dvb_mosaic_descript
 		if ((pos + sizeof(struct dvb_mosaic_info)) > len)
 			return NULL;
 
-		bswap16(buf + pos);
+		ubswap16(buf + pos);
 
 		pos += sizeof(struct dvb_mosaic_info) +
 			e->elementary_cell_field_length;
@@ -155,35 +155,35 @@ static inline struct dvb_mosaic_descript
 		case 0x01:
 			if ((pos + sizeof(struct dvb_mosaic_linkage_01)) > len)
 				return NULL;
-			bswap16(buf+pos);
+			ubswap16(buf+pos);
 			pos += sizeof(struct dvb_mosaic_linkage_01);
 			break;
 
 		case 0x02:
 			if ((pos + sizeof(struct dvb_mosaic_linkage_02)) > len)
 				return NULL;
-			bswap16(buf+pos);
-			bswap16(buf+pos+2);
-			bswap16(buf+pos+4);
+			ubswap16(buf+pos);
+			ubswap16(buf+pos+2);
+			ubswap16(buf+pos+4);
 			pos += sizeof(struct dvb_mosaic_linkage_02);
 			break;
 
 		case 0x03:
 			if ((pos + sizeof(struct dvb_mosaic_linkage_03)) > len)
 				return NULL;
-			bswap16(buf+pos);
-			bswap16(buf+pos+2);
-			bswap16(buf+pos+4);
+			ubswap16(buf+pos);
+			ubswap16(buf+pos+2);
+			ubswap16(buf+pos+4);
 			pos += sizeof(struct dvb_mosaic_linkage_03);
 			break;
 
 		case 0x04:
 			if ((pos + sizeof(struct dvb_mosaic_linkage_04)) > len)
 				return NULL;
-			bswap16(buf+pos);
-			bswap16(buf+pos+2);
-			bswap16(buf+pos+4);
-			bswap16(buf+pos+6);
+			ubswap16(buf+pos);
+			ubswap16(buf+pos+2);
+			ubswap16(buf+pos+4);
+			ubswap16(buf+pos+6);
 			pos += sizeof(struct dvb_mosaic_linkage_04);
 			break;
 		}
