$NetBSD: patch-boringssl_crypto_aes_aes__test.cc,v 1.1 2017/06/27 20:11:00 joerg Exp $

--- boringssl/crypto/aes/aes_test.cc.orig	2017-06-26 21:48:38.563416913 +0000
+++ boringssl/crypto/aes/aes_test.cc
@@ -94,7 +94,7 @@ int main() {
                                 "\x88\x99\xaa\xbb\xcc\xdd\xee\xff",
                (const uint8_t *)"\x8e\xa2\xb7\xca\x51\x67\x45\xbf"
                                 "\xea\xfc\x49\x90\x4b\x49\x60\x89")) {
-    return false;
+    return 0;
   }
 
   printf("PASS\n");
