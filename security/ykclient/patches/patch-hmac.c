$NetBSD: patch-hmac.c,v 1.1 2016/12/18 21:50:08 joerg Exp $

--- hmac.c.orig	2016-12-18 16:48:04.404560212 +0000
+++ hmac.c
@@ -36,8 +36,8 @@
  *
  */
 int
-hmac (SHAversion whichSha, const unsigned char *text, int text_len,
-      const unsigned char *key, int key_len, uint8_t digest[USHAMaxHashSize])
+ykhmac (SHAversion whichSha, const unsigned char *text, int text_len,
+        const unsigned char *key, int key_len, uint8_t digest[USHAMaxHashSize])
 {
   HMACContext ctx;
   return hmacReset (&ctx, whichSha, key, key_len) ||
