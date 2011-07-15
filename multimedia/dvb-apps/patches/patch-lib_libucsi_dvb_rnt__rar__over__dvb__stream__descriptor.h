$NetBSD: patch-lib_libucsi_dvb_rnt__rar__over__dvb__stream__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/rnt_rar_over_dvb_stream_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/rnt_rar_over_dvb_stream_descriptor.h
@@ -75,9 +75,9 @@ static inline struct dvb_rnt_rar_over_dv
 	if (len < sizeof(struct dvb_rnt_rar_over_dvb_stream_descriptor))
 		return NULL;
 
-	bswap16(buf + 13);
-	bswap16(buf + 15);
-	bswap16(buf + 17);
+	ubswap16(buf + 13);
+	ubswap16(buf + 15);
+	ubswap16(buf + 17);
 
 	if (ret->scheduled_flag == 1) {
 		if (len < (sizeof(struct dvb_rnt_rar_over_dvb_stream_descriptor)+
