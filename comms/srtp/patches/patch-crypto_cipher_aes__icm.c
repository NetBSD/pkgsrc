$NetBSD: patch-crypto_cipher_aes__icm.c,v 1.1 2015/09/14 13:30:03 joerg Exp $

--- crypto/cipher/aes_icm.c.orig	2015-09-13 19:21:36.000000000 +0000
+++ crypto/cipher/aes_icm.c
@@ -283,7 +283,7 @@ aes_icm_set_iv(aes_icm_ctx_t *c, void *i
  * this is an internal, hopefully inlined function
  */
   
-inline void
+static inline void
 aes_icm_advance_ismacryp(aes_icm_ctx_t *c, uint8_t forIsmacryp) {
   /* fill buffer with new keystream */
   v128_copy(&c->keystream_buffer, &c->counter);
@@ -308,7 +308,7 @@ aes_icm_advance_ismacryp(aes_icm_ctx_t *
   }
 }
 
-inline void aes_icm_advance(aes_icm_ctx_t *c) {
+static inline void aes_icm_advance(aes_icm_ctx_t *c) {
   aes_icm_advance_ismacryp(c, 0);
 }
 
