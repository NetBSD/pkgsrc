$NetBSD: patch-sha1dc_sha1.c,v 1.1 2017/05/24 14:41:35 martin Exp $

Upstream fix for alignement issues in SHA1DCUpdate,
see: https://public-inbox.org/git/20170515220939.vkgofpkdtpz7u26v@sigill.intra.peff.net/T/#u

--- sha1dc/sha1.c.orig	2017-05-24 14:22:01.252256885 +0200
+++ sha1dc/sha1.c	2017-05-24 14:24:53.441321730 +0200
@@ -20,7 +20,7 @@
  */
 #if (defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN)) || \
     (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __BIG_ENDIAN__)) || \
-    defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) ||  defined(__AARCH64EB__) || \
+     defined(_BIG_ENDIAN) || defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) ||  defined(__AARCH64EB__) || \
     defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__)
 
 #define SHA1DC_BIGENDIAN	1
@@ -1728,7 +1728,8 @@ void SHA1DCUpdate(SHA1_CTX* ctx, const c
 	while (len >= 64)
 	{
 		ctx->total += 64;
-		sha1_process(ctx, (uint32_t*)(buf));
+		memcpy(ctx->buffer, buf, 64);
+		sha1_process(ctx, (uint32_t*)(ctx->buffer));
 		buf += 64;
 		len -= 64;
 	}
