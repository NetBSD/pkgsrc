$NetBSD: patch-vendor_bytecount-0.6.8_src_lib.rs,v 1.1 2024/10/13 19:04:39 he Exp $

Avoid using neon on big-endian aarch64.
Ref. https://github.com/rust-lang/rust/issues/129819

--- vendor/bytecount-0.6.8/src/lib.rs.orig	2024-09-01 16:29:37.478735730 +0000
+++ vendor/bytecount-0.6.8/src/lib.rs
@@ -50,7 +50,10 @@ mod integer_simd;
         feature = "runtime-dispatch-simd",
         any(target_arch = "x86", target_arch = "x86_64")
     ),
-    target_arch = "aarch64",
+    all(
+        target_arch = "aarch64",
+        target_endian = "little"
+    ),
     target_arch = "wasm32",
     feature = "generic-simd"
 ))]
@@ -93,7 +96,11 @@ pub fn count(haystack: &[u8], needle: u8
                 }
             }
         }
-        #[cfg(all(target_arch = "aarch64", not(feature = "generic_simd")))]
+        #[cfg(all(
+            target_arch = "aarch64", 
+            target_endian = "little",
+            not(feature = "generic_simd")
+        ))]
         {
             unsafe {
                 return simd::aarch64::chunk_count(haystack, needle);
@@ -155,7 +162,11 @@ pub fn num_chars(utf8_chars: &[u8]) -> u
                 }
             }
         }
-        #[cfg(all(target_arch = "aarch64", not(feature = "generic_simd")))]
+        #[cfg(all(
+            target_arch = "aarch64",
+            target_endian = "little",
+            not(feature = "generic_simd")
+        ))]
         {
             unsafe {
                 return simd::aarch64::chunk_num_chars(utf8_chars);
