$NetBSD: patch-lib_libucsi_dvb_service__list__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/service_list_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/service_list_descriptor.h
@@ -64,7 +64,7 @@ static inline struct dvb_service_list_de
 		return NULL;
 
 	while(pos < len) {
-		bswap16(p+pos);
+		ubswap16(p+pos);
 		pos += sizeof(struct dvb_service_list_service);
 	}
 
