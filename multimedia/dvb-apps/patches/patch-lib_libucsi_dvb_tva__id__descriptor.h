$NetBSD: patch-lib_libucsi_dvb_tva__id__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/tva_id_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/tva_id_descriptor.h
@@ -66,7 +66,7 @@ static inline struct dvb_tva_id_descript
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos+=3;
 	}
 
