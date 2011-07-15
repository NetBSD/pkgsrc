$NetBSD: patch-lib_libucsi_dvb_tot__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/tot_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/tot_section.c
@@ -32,7 +32,7 @@ struct dvb_tot_section *dvb_tot_section_
 		return NULL;
 
 	pos += 5;
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	if ((pos + ret->descriptors_loop_length) > len)
