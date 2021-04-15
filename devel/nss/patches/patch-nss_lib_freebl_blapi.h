$NetBSD: patch-nss_lib_freebl_blapi.h,v 1.1 2021/04/15 08:54:54 wiz Exp $

Some symbols conflict with openssl.
If nss is loaded first, it can call into openssl's code,
which has different struct sizes. This can lead to weird
coredumps.

https://groups.google.com/a/mozilla.org/g/dev-tech-crypto/c/Al0Pt0zhARE

--- nss/lib/freebl/blapi.h.orig	2021-03-18 14:22:42.000000000 +0000
+++ nss/lib/freebl/blapi.h
@@ -1122,6 +1122,8 @@ extern void MD5_DestroyContext(MD5Contex
 */
 extern void MD5_Begin(MD5Context *cx);
 
+#define MD5_Update NSS_MD5_Update
+
 /*
 ** Update the MD5 hash function with more data.
 **  "cx" the context
@@ -1287,6 +1289,8 @@ extern void SHA1_DestroyContext(SHA1Cont
 */
 extern void SHA1_Begin(SHA1Context *cx);
 
+#define SHA1_Update NSS_SHA1_Update
+
 /*
 ** Update the SHA-1 hash function with more data.
 **  "cx" the context
