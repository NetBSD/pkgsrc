$NetBSD: patch-lib_libucsi_dvb_service__availability__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/service_availability_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/service_availability_descriptor.h
@@ -60,7 +60,7 @@ static inline struct dvb_service_availab
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos += 2;
 	}
 
