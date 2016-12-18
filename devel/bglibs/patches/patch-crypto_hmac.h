$NetBSD: patch-crypto_hmac.h,v 1.1 2016/12/18 21:39:58 joerg Exp $

--- crypto/hmac.h.orig	2016-12-18 10:43:45.246910135 +0000
+++ crypto/hmac.h
@@ -34,9 +34,9 @@ extern void hmac_finish(const struct hma
 			const void* midstate,
 			const struct str* nonce,
 			void* outout);
-extern void hmac(const struct hmac_control_block* hcb,
-		 const struct str* secret,
-		 const struct str* nonce,
-		 void* output);
+extern void bghmac(const struct hmac_control_block* hcb,
+		   const struct str* secret,
+		   const struct str* nonce,
+		   void* output);
 
 #endif
