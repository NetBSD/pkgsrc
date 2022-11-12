$NetBSD: patch-src_per__curve_eddsa.tmpl.h,v 1.1 2022/11/12 15:19:03 fox Exp $

Fix deprecated attribute for gcc

--- src/per_curve/eddsa.tmpl.h.orig	2022-07-13 12:44:55.000000000 +0000
+++ src/per_curve/eddsa.tmpl.h
@@ -143,8 +143,7 @@ void DECAF_API_VIS decaf_ed$(gf_shortnam
     uint8_t context_len
 ) __attribute__((nonnull(1,2,3))) DECAF_NOINLINE
 #if DECAF_EDDSA_NON_KEYPAIR_API_IS_DEPRECATED
-  __attribute__((deprecated("Passing the pubkey and privkey separately is unsafe",
-        "decaf_ed$(gf_shortname)_keypair_sign")))
+  DECAF_DEPRECATED("Passing the pubkey and privkey separately is unsafe, use decaf_ed$(gf_shortname)_keypair_sign")
 #endif
 ;
 
@@ -171,8 +170,7 @@ void DECAF_API_VIS decaf_ed$(gf_shortnam
     uint8_t context_len
 ) __attribute__((nonnull(1,2,3,4))) DECAF_NOINLINE
 #if DECAF_EDDSA_NON_KEYPAIR_API_IS_DEPRECATED
-  __attribute__((deprecated("Passing the pubkey and privkey separately is unsafe",
-        "decaf_ed$(gf_shortname)_keypair_sign_prehash")))
+  DECAF_DEPRECATED("Passing the pubkey and privkey separately is unsafe, use decaf_ed$(gf_shortname)_keypair_sign_prehash")
 #endif
 ;
 
