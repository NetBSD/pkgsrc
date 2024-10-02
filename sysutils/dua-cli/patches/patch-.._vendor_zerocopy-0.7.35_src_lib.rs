$NetBSD: patch-.._vendor_zerocopy-0.7.35_src_lib.rs,v 1.1 2024/10/02 17:49:02 he Exp $

Make this build on big-endian aarch64.

--- ../vendor/zerocopy-0.7.35/src/lib.rs.orig	2024-10-01 22:31:58.027833427 +0000
+++ ../vendor/zerocopy-0.7.35/src/lib.rs
@@ -3736,7 +3736,7 @@ mod simd {
             powerpc64, powerpc64, vector_bool_long, vector_double, vector_signed_long, vector_unsigned_long
         );
         simd_arch_mod!(
-            #[cfg(target_arch = "aarch64")]
+            #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
             aarch64, aarch64, float32x2_t, float32x4_t, float64x1_t, float64x2_t, int8x8_t, int8x8x2_t,
             int8x8x3_t, int8x8x4_t, int8x16_t, int8x16x2_t, int8x16x3_t, int8x16x4_t, int16x4_t,
             int16x8_t, int32x2_t, int32x4_t, int64x1_t, int64x2_t, poly8x8_t, poly8x8x2_t, poly8x8x3_t,
@@ -8026,7 +8026,7 @@ mod tests {
                 vector_signed_long,
                 vector_unsigned_long
             );
-            #[cfg(target_arch = "aarch64")]
+            #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
             #[rustfmt::skip]
             test_simd_arch_mod!(
                 aarch64, float32x2_t, float32x4_t, float64x1_t, float64x2_t, int8x8_t, int8x8x2_t,
