$NetBSD: patch-lib_libucsi_dvb_rst__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/rst_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/rst_section.c
@@ -32,10 +32,10 @@ struct dvb_rst_section * dvb_rst_section
 		if ((pos + sizeof(struct dvb_rst_status)) > len)
 			return NULL;
 
-		bswap16(buf + pos);
-		bswap16(buf + pos + 2);
-		bswap16(buf + pos + 4);
-		bswap16(buf + pos + 6);
+		ubswap16(buf + pos);
+		ubswap16(buf + pos + 2);
+		ubswap16(buf + pos + 4);
+		ubswap16(buf + pos + 6);
 
 		pos += sizeof(struct dvb_rst_status);
 	}
