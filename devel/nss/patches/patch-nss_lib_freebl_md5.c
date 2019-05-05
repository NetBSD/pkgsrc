$NetBSD: patch-nss_lib_freebl_md5.c,v 1.1 2019/05/05 22:47:28 ryoon Exp $

MD5_Update conflicts with openssl which may be dynamically loaded
at runtime via libcups or libgssapi so causing a crash due to using
the wrong binding.  So rename here to avoid conflict.

--- nss/lib/freebl/md5.c.orig	2019-03-16 00:25:08.000000000 +0000
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
 
