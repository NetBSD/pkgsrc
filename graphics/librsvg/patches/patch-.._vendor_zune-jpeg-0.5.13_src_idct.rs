$NetBSD: patch-.._vendor_zune-jpeg-0.5.13_src_idct.rs,v 1.1 2026/07/06 13:49:07 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/zune-jpeg-0.5.13/src/idct.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/zune-jpeg-0.5.13/src/idct.rs
@@ -41,7 +41,7 @@ use crate::idct::scalar::{idct_int, idct
 
 #[cfg(feature = "x86")]
 pub mod avx2;
-#[cfg(feature = "neon")]
+#[cfg(all(feature = "neon", target_endian = "little"))]
 pub mod neon;
 
 pub mod scalar;
@@ -60,7 +60,7 @@ pub fn choose_idct_func(options: &Decode
             };
         }
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     #[cfg(feature = "neon")]
     {
         if options.use_neon() {
