$NetBSD: patch-lib_libucsi_dvb_announcement__support__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/announcement_support_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/announcement_support_descriptor.h
@@ -115,7 +115,7 @@ static inline struct dvb_announcement_su
 	if (len < (sizeof(struct dvb_announcement_support_descriptor) - 2))
 		return NULL;
 
-	bswap16(buf+pos);
+	ubswap16(buf+pos);
 
 	pos += 2;
 
@@ -134,9 +134,9 @@ static inline struct dvb_announcement_su
 			if ((pos + sizeof(struct dvb_announcement_support_reference)) > len)
 				return NULL;
 
-			bswap16(buf+pos);
-			bswap16(buf+pos+2);
-			bswap16(buf+pos+4);
+			ubswap16(buf+pos);
+			ubswap16(buf+pos+2);
+			ubswap16(buf+pos+4);
 
 			pos += sizeof(struct dvb_announcement_support_reference);
 		}
