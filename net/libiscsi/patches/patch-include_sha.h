$NetBSD: patch-include_sha.h,v 1.1 2026/08/07 08:14:45 adam Exp $

Comment out unused hmac definions to avoid conflict on NetBSD.

--- include/sha.h.orig	2026-08-07 07:44:14.462361966 +0000
+++ include/sha.h
@@ -305,6 +305,7 @@ extern int USHAHashSizeBits (enum SHAversion whichSha)
 extern int USHAHashSize (enum SHAversion whichSha);
 extern int USHAHashSizeBits (enum SHAversion whichSha);
 
+#if 0
 /*
  * HMAC Keyed-Hashing for Message Authentication, RFC2104,
  * for all SHAs.
@@ -330,5 +331,6 @@ extern int hmacResult (HMACContext * ctx, uint8_t *dig
 extern int hmacFinalBits (HMACContext * ctx, const uint8_t bits,
 			  size_t bitcount);
 extern int hmacResult (HMACContext * ctx, uint8_t *digest);
+#endif
 
 #endif /* _SHA_H_ */
