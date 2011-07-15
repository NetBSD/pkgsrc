$NetBSD: patch-lib_libucsi_dvb_ait__application__icons__descriptor.h,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/dvb/ait_application_icons_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/ait_application_icons_descriptor.h
@@ -91,7 +91,7 @@ static inline struct dvb_ait_application
 
 	if ((len - pos) < sizeof(struct dvb_ait_application_icons_descriptor_part2))
 		return NULL;
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 
 	return ret;
 }
