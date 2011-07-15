$NetBSD: patch-lib_libucsi_mpeg_odsmt__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/odsmt_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/odsmt_section.c
@@ -41,7 +41,7 @@ struct mpeg_odsmt_section *mpeg_odsmt_se
 		if ((pos + sizeof(struct mpeg_odsmt_stream_single)) > len)
 			return NULL;
 
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos+=3;
 
 		if ((pos + stream->u.single.es_info_length) >= len)
@@ -59,7 +59,7 @@ struct mpeg_odsmt_section *mpeg_odsmt_se
 			if ((pos + sizeof(struct mpeg_odsmt_stream_multi)) > len)
 				return NULL;
 
-			bswap16(buf+pos);
+			ubswap16(buf+pos);
 			pos += sizeof(struct mpeg_odsmt_stream_multi);
 
 			if ((pos + stream->u.multi.es_info_length) > len)
