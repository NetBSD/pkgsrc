$NetBSD: patch-source_darkplaces_hmac.h,v 1.1 2019/10/01 12:32:26 nia Exp $

Avoid conflicting with NetBSD libc.

--- source/darkplaces/hmac.h.orig	2017-04-01 13:26:56.000000000 +0000
+++ source/darkplaces/hmac.h
@@ -2,14 +2,14 @@
 #define HMAC_H
 
 typedef void (*hashfunc_t) (unsigned char *out, const unsigned char *in, int n);
-qboolean hmac(
+qboolean darkplaces_hmac(
 	hashfunc_t hfunc, int hlen, int hblock,
 	unsigned char *out,
 	const unsigned char *in, int n,
 	const unsigned char *key, int k
 );
 
-#define HMAC_MDFOUR_16BYTES(out, in, n, key, k) hmac(mdfour, 16, 64, out, in, n, key, k)
-#define HMAC_SHA256_32BYTES(out, in, n, key, k) hmac(sha256, 32, 64, out, in, n, key, k)
+#define HMAC_MDFOUR_16BYTES(out, in, n, key, k) darkplaces_hmac(mdfour, 16, 64, out, in, n, key, k)
+#define HMAC_SHA256_32BYTES(out, in, n, key, k) darkplaces_hmac(sha256, 32, 64, out, in, n, key, k)
 
 #endif
