$NetBSD: patch-src_pk_rsa_rsa__verify__hash.c,v 1.1 2017/05/16 21:55:50 snj Exp $

Fix for CVE-2016-6129.  

Source: https://github.com/libtom/libtomcrypt/commit/5eb9743410ce4657e9d54fef26a2ee31a1b5dd09

--- src/pk/rsa/rsa_verify_hash.c.orig	2007-05-12 07:46:25.000000000 -0700
+++ src/pk/rsa/rsa_verify_hash.c	2017-05-16 13:42:46.762259864 -0700
@@ -96,7 +96,7 @@ int rsa_verify_hash_ex(const unsigned ch
   } else {
     /* LTC_PKCS #1 v1.5 decode it */
     unsigned char *out;
-    unsigned long outlen, loid[16];
+    unsigned long outlen, loid[16], reallen;
     int           decoded;
     ltc_asn1_list digestinfo[2], siginfo[2];
 
@@ -138,8 +138,14 @@ int rsa_verify_hash_ex(const unsigned ch
        goto bail_2;
     }
 
+    if ((err = der_length_sequence(siginfo, 2, &reallen)) != CRYPT_OK) {
+       XFREE(out);
+       goto bail_2;
+    }
+
     /* test OID */
-    if ((digestinfo[0].size == hash_descriptor[hash_idx].OIDlen) &&
+    if ((reallen == outlen) &&
+        (digestinfo[0].size == hash_descriptor[hash_idx].OIDlen) &&
         (XMEMCMP(digestinfo[0].data, hash_descriptor[hash_idx].OID, sizeof(unsigned long) * hash_descriptor[hash_idx].OIDlen) == 0) &&
         (siginfo[1].size == hashlen) &&
         (XMEMCMP(siginfo[1].data, hash, hashlen) == 0)) {
