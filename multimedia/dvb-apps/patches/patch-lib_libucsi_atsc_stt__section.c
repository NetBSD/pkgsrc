$NetBSD: patch-lib_libucsi_atsc_stt__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/stt_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/stt_section.c
@@ -30,9 +30,9 @@ struct atsc_stt_section *atsc_stt_sectio
 	if (len < sizeof(struct atsc_stt_section))
 		return NULL;
 
-	bswap32(buf + pos);
+	ubswap32(buf + pos);
 	pos += 5;
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	if (verify_descriptors(buf + pos, len - sizeof(struct atsc_stt_section)))
