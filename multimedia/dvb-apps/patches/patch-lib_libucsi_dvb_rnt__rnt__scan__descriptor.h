$NetBSD: patch-lib_libucsi_dvb_rnt__rnt__scan__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/rnt_rnt_scan_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/rnt_rnt_scan_descriptor.h
@@ -66,8 +66,8 @@ static inline struct dvb_rnt_rnt_scan_de
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
-		bswap16(buf+pos+2);
+		ubswap16(buf+pos);
+		ubswap16(buf+pos+2);
 		pos += sizeof(struct dvb_rnt_rnt_scan_entry);
 	}
 
