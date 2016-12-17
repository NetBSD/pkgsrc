$NetBSD: patch-src-IL_src_il__jp2.c,v 1.1 2016/12/17 14:15:27 joerg Exp $

--- src-IL/src/il_jp2.c.orig	2016-12-17 13:58:54.173364828 +0000
+++ src-IL/src/il_jp2.c
@@ -459,7 +459,7 @@ static void jas_stream_initbuf(jas_strea
 			/* The buffer must be large enough to accommodate maximum
 			  putback. */
 			assert(bufsize > JAS_STREAM_MAXPUTBACK);
-			stream->bufbase_ = JAS_CAST(uchar *, buf);
+			stream->bufbase_ = JAS_CAST(unsigned char *, buf);
 			stream->bufsize_ = bufsize - JAS_STREAM_MAXPUTBACK;
 		}
 	} else {
