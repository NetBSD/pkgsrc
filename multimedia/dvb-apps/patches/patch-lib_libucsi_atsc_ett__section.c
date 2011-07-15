$NetBSD: patch-lib_libucsi_atsc_ett__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/ett_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/ett_section.c
@@ -31,7 +31,7 @@ struct atsc_ett_section *atsc_ett_sectio
 	if (len < sizeof(struct atsc_ett_section))
 		return NULL;
 
-	bswap32(buf + pos);
+	ubswap32(buf + pos);
 	pos += 4;
 
 	if (atsc_text_validate(buf + pos,
