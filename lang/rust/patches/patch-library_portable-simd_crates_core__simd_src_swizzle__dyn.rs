$NetBSD: patch-library_portable-simd_crates_core__simd_src_swizzle__dyn.rs,v 1.1 2023/10/10 13:12:33 pin Exp $

Apply https://github.com/rust-lang/portable-simd/pull/348/files
to fix build on big-endian arm / arm64.

--- library/portable-simd/crates/core_simd/src/swizzle_dyn.rs.orig	2023-08-03 12:13:07.000000000 +0000
+++ library/portable-simd/crates/core_simd/src/swizzle_dyn.rs
@@ -16,9 +16,9 @@ where
     #[inline]
     pub fn swizzle_dyn(self, idxs: Simd<u8, N>) -> Self {
         #![allow(unused_imports, unused_unsafe)]
-        #[cfg(target_arch = "aarch64")]
+        #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
         use core::arch::aarch64::{uint8x8_t, vqtbl1q_u8, vtbl1_u8};
-        #[cfg(all(target_arch = "arm", target_feature = "v7", target_feature = "neon"))]
+        #[cfg(all(target_arch = "arm", target_feature = "v7", target_feature = "neon", target_endian = "little"))]
         use core::arch::arm::{uint8x8_t, vtbl1_u8};
         #[cfg(target_arch = "wasm32")]
         use core::arch::wasm32 as wasm;
@@ -29,13 +29,24 @@ where
         // SAFETY: Intrinsics covered by cfg
         unsafe {
             match N {
-                #[cfg(target_feature = "neon")]
+                #[cfg(all(
+                    any(
+                        target_arch = "aarch64",
+                        all(target_arch = "arm", target_feature = "v7")
+                    ),
+                    target_feature = "neon",
+                    target_endian = "little"
+                ))]
                 8 => transize(vtbl1_u8, self, idxs),
                 #[cfg(target_feature = "ssse3")]
                 16 => transize(x86::_mm_shuffle_epi8, self, idxs),
                 #[cfg(target_feature = "simd128")]
                 16 => transize(wasm::i8x16_swizzle, self, idxs),
-                #[cfg(all(target_arch = "aarch64", target_feature = "neon"))]
+                #[cfg(all(
+                    target_arch = "aarch64",
+                    target_feature = "neon",
+                    target_endian = "little"
+                ))]
                 16 => transize(vqtbl1q_u8, self, idxs),
                 #[cfg(all(target_feature = "avx2", not(target_feature = "avx512vbmi")))]
                 32 => transize_raw(avx2_pshufb, self, idxs),
