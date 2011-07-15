$NetBSD: patch-lib_libucsi_dvb_mhp__data__broadcast__id__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/mhp_data_broadcast_id_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/mhp_data_broadcast_id_descriptor.h
@@ -72,7 +72,7 @@ static inline struct dvb_mhp_data_broadc
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos+=2;
 	}
 
