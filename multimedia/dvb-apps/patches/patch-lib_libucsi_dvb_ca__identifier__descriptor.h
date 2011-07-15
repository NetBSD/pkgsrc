$NetBSD: patch-lib_libucsi_dvb_ca__identifier__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/ca_identifier_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/ca_identifier_descriptor.h
@@ -56,7 +56,7 @@ static inline struct dvb_ca_identifier_d
 		return NULL;
 
 	while(pos < len) {
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos+=2;
 	}
 
