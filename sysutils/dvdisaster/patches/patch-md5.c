$NetBSD: patch-md5.c,v 1.1 2015/04/26 13:30:58 joerg Exp $

--- md5.c.orig	2015-04-26 11:58:37.000000000 +0000
+++ md5.c
@@ -159,7 +159,7 @@ MD5Final(unsigned char digest[16], struc
 	MD5Transform(ctx->buf, (guint32 *) ctx->in);
 	byteReverse((unsigned char *) ctx->buf, 4);
 	memmove(digest, ctx->buf, 16);
-	memset(ctx, 0, sizeof (ctx));	/* In case it's sensitive */
+	memset(ctx, 0, sizeof (*ctx));	/* In case it's sensitive */
 }
 
 /* The four core functions - F1 is optimized somewhat */
