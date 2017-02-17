$NetBSD: patch-plugins_cdrcimg_cdrcimg.c,v 1.1 2017/02/17 17:02:01 joerg Exp $

--- plugins/cdrcimg/cdrcimg.c.orig	2017-02-17 14:01:41.343339778 +0000
+++ plugins/cdrcimg/cdrcimg.c
@@ -98,7 +98,7 @@ static long CDRgetTD(unsigned char track
 	return 0;
 }
 
-int uncompress2(void *out, unsigned long *out_size, void *in, unsigned long in_size)
+static int my_uncompress2(void *out, unsigned long *out_size, void *in, unsigned long in_size)
 {
 	static z_stream z;
 	int ret = 0;
@@ -199,7 +199,7 @@ static long CDRreadTrack(unsigned char *
 		ret = uncompress(cdbuffer->raw[0], &cdbuffer_size, cdbuffer->compressed, size);
 		break;
 	case CDRC_ZLIB2:
-		ret = uncompress2(cdbuffer->raw[0], &cdbuffer_size, cdbuffer->compressed, size);
+		ret = my_uncompress2(cdbuffer->raw[0], &cdbuffer_size, cdbuffer->compressed, size);
 		break;
 	case CDRC_BZ:
 		ret = pBZ2_bzBuffToBuffDecompress((char *)cdbuffer->raw, (unsigned int *)&cdbuffer_size,
