$NetBSD: patch-.._vendor_zune-jpeg-0.4.14_src_idct.rs,v 1.1 2025/09/23 11:12:17 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/zune-jpeg-0.4.14/src/idct.rs.orig	2025-02-15 21:55:11.774911146 +0000
+++ ../vendor/zune-jpeg-0.4.14/src/idct.rs
@@ -41,7 +41,7 @@ use crate::idct::scalar::idct_int;
 
 #[cfg(feature = "x86")]
 pub mod avx2;
-#[cfg(feature = "neon")]
+#[cfg(all(feature = "neon", target_endian = "little"))]
 pub mod neon;
 
 pub mod scalar;
@@ -58,7 +58,7 @@ pub fn choose_idct_func(options: &Decode
             return crate::idct::avx2::idct_avx2;
         }
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     #[cfg(feature = "neon")]
     {
         if options.use_neon() {
@@ -129,7 +129,7 @@ mod tests {
 
     fn idct_fnc() -> IDCTPtr {
         #[cfg(feature = "neon")]
-        #[cfg(target_arch = "aarch64")]
+        #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
         {
             use crate::idct::neon::idct_neon;
             return idct_neon;
