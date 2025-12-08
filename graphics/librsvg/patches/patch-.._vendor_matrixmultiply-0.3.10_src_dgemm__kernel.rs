$NetBSD: patch-.._vendor_matrixmultiply-0.3.10_src_dgemm__kernel.rs,v 1.1 2025/12/08 12:40:15 adam Exp $

Do not try to use neon / SIMD on big-endian aarch64.

--- ../vendor/matrixmultiply-0.3.10/src/dgemm_kernel.rs.orig	2025-02-15 22:01:28.532125465 +0000
+++ ../vendor/matrixmultiply-0.3.10/src/dgemm_kernel.rs
@@ -28,7 +28,7 @@ struct KernelFma;
 #[cfg(any(target_arch="x86", target_arch="x86_64"))]
 struct KernelSse2;
 
-#[cfg(target_arch="aarch64")]
+#[cfg(all(target_arch="aarch64", target_endian = "little"))]
 #[cfg(has_aarch64_simd)]
 struct KernelNeon;
 
@@ -58,7 +58,7 @@ pub(crate) fn detect<G>(selector: G) whe
         }
     }
 
-    #[cfg(target_arch="aarch64")]
+    #[cfg(all(target_arch="aarch64", target_endian = "little"))]
     #[cfg(has_aarch64_simd)]
     {
         if is_aarch64_feature_detected_!("neon") {
@@ -232,7 +232,7 @@ impl GemmKernel for KernelSse2 {
     }
 }
 
-#[cfg(target_arch="aarch64")]
+#[cfg(all(target_arch="aarch64", target_endian = "little"))]
 #[cfg(has_aarch64_simd)]
 impl GemmKernel for KernelNeon {
     type Elem = T;
@@ -880,7 +880,7 @@ unsafe fn kernel_x86_avx<MA>(k: usize, a
     }
 }
 
-#[cfg(target_arch="aarch64")]
+#[cfg(all(target_arch="aarch64", target_endian = "little"))]
 #[cfg(has_aarch64_simd)]
 #[target_feature(enable="neon")]
 unsafe fn kernel_target_neon(k: usize, alpha: T, a: *const T, b: *const T,
@@ -1065,7 +1065,7 @@ mod tests {
         }
     }
 
-    #[cfg(any(target_arch="aarch64"))]
+    #[cfg(any(all(target_arch="aarch64", target_endian = "little")))]
     #[cfg(has_aarch64_simd)]
     mod test_kernel_aarch64 {
         use super::test_a_kernel;
