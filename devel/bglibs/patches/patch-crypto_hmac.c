$NetBSD: patch-crypto_hmac.c,v 1.1 2016/12/18 21:39:58 joerg Exp $

--- crypto/hmac.c.orig	2016-12-18 09:58:18.626636990 +0000
+++ crypto/hmac.c
@@ -101,7 +101,7 @@ void hmac_finish(const struct hmac_contr
  * Authentication) according to RFC 2104, using a secure hash given in
  * the control block.
  */
-void hmac(const struct hmac_control_block* hcb,
+void bghmac(const struct hmac_control_block* hcb,
 	  const str* secret,
 	  const str* nonce,
 	  void* output)
