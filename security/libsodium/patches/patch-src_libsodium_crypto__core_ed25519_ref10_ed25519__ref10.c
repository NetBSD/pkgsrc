$NetBSD: patch-src_libsodium_crypto__core_ed25519_ref10_ed25519__ref10.c,v 1.1 2025/12/31 00:13:22 wiz Exp $

core_ed25519_is_valid_point: check Y==Z in addition to X==0
https://github.com/jedisct1/libsodium/commit/f2da4cd8cb26599a0285a6ab0c02948e361a674a

--- src/libsodium/crypto_core/ed25519/ref10/ed25519_ref10.c.orig	2024-05-25 12:15:18.000000000 +0000
+++ src/libsodium/crypto_core/ed25519/ref10/ed25519_ref10.c
@@ -1029,10 +1029,13 @@ int
 ge25519_is_on_main_subgroup(const ge25519_p3 *p)
 {
     ge25519_p3 pl;
+    fe25519    t;
 
     ge25519_mul_l(&pl, p);
 
-    return fe25519_iszero(pl.X);
+    fe25519_sub(t, pl.Y, pl.Z);
+
+    return fe25519_iszero(pl.X) & fe25519_iszero(t);
 }
 
 int
