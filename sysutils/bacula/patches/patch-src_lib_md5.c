$NetBSD: patch-src_lib_md5.c,v 1.1 2013/11/06 16:00:05 joerg Exp $

--- src/lib/md5.c.orig	2013-11-06 15:37:34.000000000 +0000
+++ src/lib/md5.c
@@ -173,7 +173,7 @@ void MD5Final(unsigned char digest[16], 
     MD5Transform(ctx->buf, (uint32_t *) ctx->in);
     byteReverse((unsigned char *) ctx->buf, 4);
     memcpy(digest, ctx->buf, 16);
-    memset(ctx, 0, sizeof(ctx));        /* In case it's sensitive */
+    memset(ctx, 0, sizeof(*ctx));        /* In case it's sensitive */
 }
 
 
