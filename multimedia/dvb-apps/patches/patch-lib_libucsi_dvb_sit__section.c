$NetBSD: patch-lib_libucsi_dvb_sit__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/sit_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/sit_section.c
@@ -31,7 +31,7 @@ struct dvb_sit_section * dvb_sit_section
 	if (len < sizeof(struct dvb_sit_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	if ((pos + ret->transmission_info_loop_length) > len)
@@ -48,9 +48,9 @@ struct dvb_sit_section * dvb_sit_section
 		if ((pos + sizeof(struct dvb_sit_service)) > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 2);
-		bswap16(buf + pos + 4);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 2);
+		ubswap16(buf + pos + 4);
 		pos += sizeof(struct dvb_sit_service);
 
 		if ((pos + service->service_loop_length) > len)
