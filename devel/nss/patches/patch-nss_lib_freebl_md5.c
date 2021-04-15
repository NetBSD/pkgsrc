$NetBSD: patch-nss_lib_freebl_md5.c,v 1.3 2021/04/15 08:54:54 wiz Exp $

Some symbols conflict with openssl.
If nss is loaded first, it can call into openssl's code,
which has different struct sizes. This can lead to weird
coredumps.

https://groups.google.com/a/mozilla.org/g/dev-tech-crypto/c/Al0Pt0zhARE

--- nss/lib/freebl/md5.c.orig	2021-03-18 14:22:42.000000000 +0000
+++ nss/lib/freebl/md5.c
@@ -205,7 +205,7 @@ MD5_HashBuf(unsigned char *dest, const u
     MD5Context cx;
 
     MD5_Begin(&cx);
-    MD5_Update(&cx, src, src_length);
+    NSS_MD5_Update(&cx, src, src_length);
     MD5_End(&cx, dest, &len, MD5_HASH_LEN);
     memset(&cx, 0, sizeof cx);
     return SECSuccess;
@@ -419,7 +419,7 @@ md5_compress(MD5Context *cx, const PRUin
 }
 
 void
-MD5_Update(MD5Context *cx, const unsigned char *input, unsigned int inputLen)
+NSS_MD5_Update(MD5Context *cx, const unsigned char *input, unsigned int inputLen)
 {
     PRUint32 bytesToConsume;
     PRUint32 inBufIndex = cx->lsbInput & 63;
@@ -509,9 +509,9 @@ MD5_End(MD5Context *cx, unsigned char *d
     lowInput <<= 3;
 
     if (inBufIndex < MD5_END_BUFFER) {
-        MD5_Update(cx, padbytes, MD5_END_BUFFER - inBufIndex);
+        NSS_MD5_Update(cx, padbytes, MD5_END_BUFFER - inBufIndex);
     } else {
-        MD5_Update(cx, padbytes,
+        NSS_MD5_Update(cx, padbytes,
                    MD5_END_BUFFER + MD5_BUFFER_SIZE - inBufIndex);
     }
 
