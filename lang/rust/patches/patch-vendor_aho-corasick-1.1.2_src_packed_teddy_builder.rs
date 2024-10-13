$NetBSD: patch-vendor_aho-corasick-1.1.2_src_packed_teddy_builder.rs,v 1.1 2024/10/13 19:04:39 he Exp $

Avoid use of neon / SIMD on big-endian aarch64.

--- vendor/aho-corasick-1.1.2/src/packed/teddy/builder.rs.orig	2024-09-29 08:19:52.405194911 +0000
+++ vendor/aho-corasick-1.1.2/src/packed/teddy/builder.rs
@@ -230,7 +230,7 @@ impl Builder {
                 }
             }
         }
-        #[cfg(target_arch = "aarch64")]
+        #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
         {
             use self::aarch64::SlimNeon;
 
@@ -301,7 +301,7 @@ impl Builder {
         }
         #[cfg(not(any(
             all(target_arch = "x86_64", target_feature = "sse2"),
-            target_arch = "aarch64"
+            all(target_arch = "aarch64", target_endian = "little")
         )))]
         {
             None
@@ -705,7 +705,7 @@ mod x86_64 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64 {
     use core::arch::aarch64::uint8x16_t;
 
