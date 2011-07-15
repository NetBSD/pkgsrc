$NetBSD: patch-lib_libucsi_dvb_bat__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/bat_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/bat_section.c
@@ -31,7 +31,7 @@ struct dvb_bat_section * dvb_bat_section
 	if (len < sizeof(struct dvb_bat_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	if ((pos + ret->bouquet_descriptors_length) > len)
@@ -44,7 +44,7 @@ struct dvb_bat_section * dvb_bat_section
 	if ((pos + sizeof(struct dvb_bat_section_part2)) > len)
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += sizeof(struct dvb_bat_section_part2);
 
 	while (pos < len) {
@@ -54,9 +54,9 @@ struct dvb_bat_section * dvb_bat_section
 		if ((pos + sizeof(struct dvb_bat_transport))  > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 2);
-		bswap16(buf + pos + 4);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 2);
+		ubswap16(buf + pos + 4);
 
 		pos += sizeof(struct dvb_bat_transport);
 
