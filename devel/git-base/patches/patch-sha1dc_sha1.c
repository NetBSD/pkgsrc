$NetBSD: patch-sha1dc_sha1.c,v 1.2 2017/05/25 03:04:05 soda Exp $

Upstream fix for alignement issues in SHA1DCUpdate,
see: https://public-inbox.org/git/20170515220939.vkgofpkdtpz7u26v@sigill.intra.peff.net/T/#u

--- sha1dc/sha1.c.orig	2017-05-09 14:47:28.000000000 +0000
+++ sha1dc/sha1.c
@@ -20,6 +20,7 @@
  */
 #if (defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN)) || \
     (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __BIG_ENDIAN__)) || \
+    (defined(_BYTE_ORDER) && (_BYTE_ORDER == _BIG_ENDIAN)) || \
     defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) ||  defined(__AARCH64EB__) || \
     defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__)
 
@@ -1728,7 +1729,8 @@ void SHA1DCUpdate(SHA1_CTX* ctx, const c
 	while (len >= 64)
 	{
 		ctx->total += 64;
-		sha1_process(ctx, (uint32_t*)(buf));
+		memcpy(ctx->buffer, buf, 64);
+		sha1_process(ctx, (uint32_t*)(ctx->buffer));
 		buf += 64;
 		len -= 64;
 	}
