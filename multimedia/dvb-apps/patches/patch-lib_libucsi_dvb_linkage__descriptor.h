$NetBSD: patch-lib_libucsi_dvb_linkage__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/linkage_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/linkage_descriptor.h
@@ -144,9 +144,9 @@ static inline struct dvb_linkage_descrip
 	if (len < (sizeof(struct dvb_linkage_descriptor) - 2))
 		return NULL;
 
-	bswap16(buf);
-	bswap16(buf+2);
-	bswap16(buf+4);
+	ubswap16(buf);
+	ubswap16(buf+2);
+	ubswap16(buf+4);
 
 	pos += sizeof(struct dvb_linkage_descriptor) - 2;
 
@@ -164,14 +164,14 @@ static inline struct dvb_linkage_descrip
 		case 3:
 			if ((len - pos) < 2)
 				return NULL;
-			bswap16(buf+pos);
+			ubswap16(buf+pos);
 			pos += 2;
 			break;
 		}
 		if (d08->origin_type == 0) {
 			if ((len - pos) < 2)
 				return NULL;
-			bswap16(buf+pos);
+			ubswap16(buf+pos);
 			pos+=2;
 		}
 
@@ -187,7 +187,7 @@ static inline struct dvb_linkage_descrip
 			return NULL;
 
 		while (pos2 < l_0b->platform_id_data_length) {
-			bswap32(buf + pos + pos2);
+			ubswap32(buf + pos + pos2);
 
 			struct dvb_platform_id *p_id = (struct dvb_platform_id *) (buf + pos + pos2);
 			if ((len - pos - pos2) < p_id->platform_name_loop_length)
@@ -207,7 +207,7 @@ static inline struct dvb_linkage_descrip
 		if (l_0c->table_type == 0x02) {
 			if ((len - pos) < 2)
 				return NULL;
-			bswap16(buf+pos);
+			ubswap16(buf+pos);
 		}
 	}
 
