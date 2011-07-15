$NetBSD: patch-lib_libucsi_dvb_sdt__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/sdt_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/sdt_section.c
@@ -30,7 +30,7 @@ struct dvb_sdt_section * dvb_sdt_section
 	if (len < sizeof(struct dvb_sdt_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 3;
 
 	while (pos < len) {
@@ -40,8 +40,8 @@ struct dvb_sdt_section * dvb_sdt_section
 		if ((pos + sizeof(struct dvb_sdt_service)) > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 3);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 3);
 		pos += sizeof(struct dvb_sdt_service);
 
 		if ((pos + service->descriptors_loop_length) > len)
