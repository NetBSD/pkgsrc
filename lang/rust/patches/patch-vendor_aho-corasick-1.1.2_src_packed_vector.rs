$NetBSD: patch-vendor_aho-corasick-1.1.2_src_packed_vector.rs,v 1.1 2024/10/13 19:04:39 he Exp $

Avoid use of neon / SIMD on big-endian aarch64.

--- vendor/aho-corasick-1.1.2/src/packed/vector.rs.orig	2024-09-29 08:09:15.720814688 +0000
+++ vendor/aho-corasick-1.1.2/src/packed/vector.rs
@@ -595,7 +595,7 @@ mod x86_64_avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64_neon {
     use core::arch::aarch64::*;
 
@@ -1466,7 +1466,11 @@ mod tests_x86_64_avx2 {
     }
 }
 
-#[cfg(all(test, target_arch = "aarch64", target_feature = "neon"))]
+#[cfg(all(test,
+          target_arch = "aarch64",
+          target_feature = "neon",
+          target_endian = "little"
+))]
 mod tests_aarch64_neon {
     use core::arch::aarch64::*;
 
