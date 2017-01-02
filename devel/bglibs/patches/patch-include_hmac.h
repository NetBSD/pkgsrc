$NetBSD: patch-include_hmac.h,v 1.1 2017/01/02 02:18:30 schmonz Exp $

Rename hmac to bghmac.

--- include/hmac.h.orig	2015-02-06 23:57:34.000000000 +0000
+++ include/hmac.h
@@ -34,7 +34,7 @@ extern void hmac_finish(const struct hma
 			const void* midstate,
 			const struct str* nonce,
 			void* outout);
-extern void hmac(const struct hmac_control_block* hcb,
+extern void bghmac(const struct hmac_control_block* hcb,
 		 const struct str* secret,
 		 const struct str* nonce,
 		 void* output);
