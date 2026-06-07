$NetBSD: patch-fticks__hashmac.c,v 1.1 2026/06/07 17:45:46 adam Exp $

Add support for Nettle 4.0
https://github.com/radsecproxy/radsecproxy/pull/197

--- fticks_hashmac.c.orig	2025-03-24 07:29:17.000000000 +0000
+++ fticks_hashmac.c
@@ -5,7 +5,8 @@
 #include <ctype.h>
 #include <errno.h>
 #include <nettle/hmac.h>
-#include <nettle/sha.h>
+#include <nettle/sha2.h>
+#include <nettle/version.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -35,7 +36,11 @@ static void _hash(const uint8_t *in,
 
         sha256_init(&ctx);
         sha256_update(&ctx, strlen((char *)in), in);
+#if NETTLE_VERSION_MAJOR >= 4
+        sha256_digest(&ctx, hash);
+#else
         sha256_digest(&ctx, sizeof(hash), hash);
+#endif
         _format_hash(hash, out_len, out);
     } else {
         struct hmac_sha256_ctx ctx;
@@ -43,7 +48,11 @@ static void _hash(const uint8_t *in,
 
         hmac_sha256_set_key(&ctx, strlen((char *)key), key);
         hmac_sha256_update(&ctx, strlen((char *)in), in);
+#if NETTLE_VERSION_MAJOR >= 4
+        hmac_sha256_digest(&ctx, hash);
+#else
         hmac_sha256_digest(&ctx, sizeof(hash), hash);
+#endif
         _format_hash(hash, out_len, out);
     }
 }
