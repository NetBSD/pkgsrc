$NetBSD: patch-third__party_rust_packed__simd_src_lib.rs,v 1.1 2021/12/01 13:11:03 wiz Exp $

Fix build with rust-1.56.1, based on firefox-95.

--- third_party/rust/packed_simd/src/lib.rs.orig	2021-10-22 11:38:34.000000000 +0000
+++ third_party/rust/packed_simd/src/lib.rs
@@ -199,7 +199,7 @@
 //!   Numeric casts are not very "precise": sometimes lossy, sometimes value
 //!   preserving, etc.
 
-#![cfg_attr(use_const_generics, feature(const_generics))]
+#![cfg_attr(use_const_generics, feature(adt_const_params))]
 #![cfg_attr(use_const_generics, allow(incomplete_features, clippy::from_over_into))]
 #![feature(
     repr_simd,
