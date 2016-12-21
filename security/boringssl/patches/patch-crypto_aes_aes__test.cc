$NetBSD: patch-crypto_aes_aes__test.cc,v 1.1 2016/12/21 13:38:16 joerg Exp $

main() does not return bool.

--- crypto/aes/aes_test.cc.orig	2016-12-21 00:28:18.783846441 +0000
+++ crypto/aes/aes_test.cc
@@ -94,7 +94,7 @@ int main() {
                                 "\x88\x99\xaa\xbb\xcc\xdd\xee\xff",
                (const uint8_t *)"\x8e\xa2\xb7\xca\x51\x67\x45\xbf"
                                 "\xea\xfc\x49\x90\x4b\x49\x60\x89")) {
-    return false;
+    return 0;
   }
 
   printf("PASS\n");
