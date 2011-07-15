$NetBSD: patch-lib_libucsi_dvb_ait__application__descriptor.h,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/dvb/ait_application_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/ait_application_descriptor.h
@@ -99,7 +99,7 @@ static inline struct dvb_ait_application
 	pos += sizeof(struct dvb_ait_application_descriptor);
 	pos2 = 0;
 	while(pos2 < ret->application_profiles_length) {
-		bswap16(buf + pos + pos2);
+		ubswap16(buf + pos + pos2);
 		pos2 += sizeof(struct dvb_ait_application_descriptor);
 	}
 	pos += pos2;
