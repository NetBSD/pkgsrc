$NetBSD: patch-lib_libucsi_dvb_nvod__reference__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/nvod_reference_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/nvod_reference_descriptor.h
@@ -65,9 +65,9 @@ static inline struct dvb_nvod_reference_
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
-		bswap16(buf+pos+2);
-		bswap16(buf+pos+4);
+		ubswap16(buf+pos);
+		ubswap16(buf+pos+2);
+		ubswap16(buf+pos+4);
 		pos += sizeof(struct dvb_nvod_reference);
 	}
 
