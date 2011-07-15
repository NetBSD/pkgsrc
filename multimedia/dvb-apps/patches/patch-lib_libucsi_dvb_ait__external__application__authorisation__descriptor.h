$NetBSD: patch-lib_libucsi_dvb_ait__external__application__authorisation__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/ait_external_application_authorisation_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/ait_external_application_authorisation_descriptor.h
@@ -66,8 +66,8 @@ static inline struct dvb_ait_external_ap
 		return NULL;
 
 	while(pos < len) {
-		bswap32(buf + pos);
-		bswap32(buf + pos + 4);
+		ubswap32(buf + pos);
+		ubswap32(buf + pos + 4);
 		pos += sizeof(struct dvb_ait_external_application_authorisation);
 	}
 
