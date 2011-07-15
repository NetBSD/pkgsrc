$NetBSD: patch-lib_libucsi_mpeg_pmt__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/pmt_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/pmt_section.c
@@ -31,9 +31,9 @@ struct mpeg_pmt_section * mpeg_pmt_secti
 	if (len < sizeof(struct mpeg_pmt_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	if ((pos + pmt->program_info_length) > len)
@@ -51,8 +51,8 @@ struct mpeg_pmt_section * mpeg_pmt_secti
 		if ((pos + sizeof(struct mpeg_pmt_stream)) > len)
 			return NULL;
 
-		bswap16(buf + pos + 1);
-		bswap16(buf + pos + 3);
+		ubswap16(buf + pos + 1);
+		ubswap16(buf + pos + 3);
 		pos += sizeof(struct mpeg_pmt_stream);
 
 		if ((pos + stream->es_info_length) > len)
