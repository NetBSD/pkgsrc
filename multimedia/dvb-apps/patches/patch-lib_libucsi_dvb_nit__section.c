$NetBSD: patch-lib_libucsi_dvb_nit__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/nit_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/nit_section.c
@@ -31,7 +31,7 @@ struct dvb_nit_section *dvb_nit_section_
 	if (len < sizeof(struct dvb_nit_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	if ((pos + ret->network_descriptors_length) > len)
@@ -45,7 +45,7 @@ struct dvb_nit_section *dvb_nit_section_
 	if ((pos + sizeof(struct dvb_nit_section_part2)) > len)
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	while (pos < len) {
@@ -55,9 +55,9 @@ struct dvb_nit_section *dvb_nit_section_
 		if ((pos + sizeof(struct dvb_nit_transport)) > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 2);
-		bswap16(buf + pos + 4);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 2);
+		ubswap16(buf + pos + 4);
 
 		pos += sizeof(struct dvb_nit_transport);
 
