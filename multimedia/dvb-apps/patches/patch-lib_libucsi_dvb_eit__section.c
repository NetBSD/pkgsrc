$NetBSD: patch-lib_libucsi_dvb_eit__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/eit_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/eit_section.c
@@ -30,9 +30,9 @@ struct dvb_eit_section *dvb_eit_section_
 	if (len < sizeof(struct dvb_eit_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 4;
 
 	while (pos < len) {
@@ -42,8 +42,8 @@ struct dvb_eit_section *dvb_eit_section_
 		if ((pos + sizeof(struct dvb_eit_event)) > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 10);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 10);
 
 		pos += sizeof(struct dvb_eit_event);
 
