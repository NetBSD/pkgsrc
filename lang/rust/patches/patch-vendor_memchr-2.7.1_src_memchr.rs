$NetBSD: patch-vendor_memchr-2.7.1_src_memchr.rs,v 1.1 2024/10/13 19:04:40 he Exp $

Only use neon extension on little-endian aarch64.
Ref. https://github.com/rust-lang/rust/issues/129819

--- vendor/memchr-2.7.1/src/memchr.rs.orig	2024-09-29 15:11:13.260160791 +0000
+++ vendor/memchr-2.7.1/src/memchr.rs
@@ -518,14 +518,14 @@ unsafe fn memchr_raw(
     {
         crate::arch::wasm32::memchr::memchr_raw(needle, start, end)
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::memchr_raw(needle, start, end)
     }
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::One::new(needle).find_raw(start, end)
@@ -551,14 +551,14 @@ unsafe fn memrchr_raw(
     {
         crate::arch::wasm32::memchr::memrchr_raw(needle, start, end)
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::memrchr_raw(needle, start, end)
     }
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::One::new(needle).rfind_raw(start, end)
@@ -585,14 +585,14 @@ unsafe fn memchr2_raw(
     {
         crate::arch::wasm32::memchr::memchr2_raw(needle1, needle2, start, end)
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::memchr2_raw(needle1, needle2, start, end)
     }
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::Two::new(needle1, needle2)
@@ -620,7 +620,7 @@ unsafe fn memrchr2_raw(
     {
         crate::arch::wasm32::memchr::memrchr2_raw(needle1, needle2, start, end)
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::memrchr2_raw(
             needle1, needle2, start, end,
@@ -629,7 +629,7 @@ unsafe fn memrchr2_raw(
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::Two::new(needle1, needle2)
@@ -662,7 +662,7 @@ unsafe fn memchr3_raw(
             needle1, needle2, needle3, start, end,
         )
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::memchr3_raw(
             needle1, needle2, needle3, start, end,
@@ -671,7 +671,7 @@ unsafe fn memchr3_raw(
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::Three::new(needle1, needle2, needle3)
@@ -704,7 +704,7 @@ unsafe fn memrchr3_raw(
             needle1, needle2, needle3, start, end,
         )
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::memrchr3_raw(
             needle1, needle2, needle3, start, end,
@@ -713,7 +713,7 @@ unsafe fn memrchr3_raw(
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::Three::new(needle1, needle2, needle3)
@@ -736,14 +736,14 @@ unsafe fn count_raw(needle: u8, start: *
     {
         crate::arch::wasm32::memchr::count_raw(needle, start, end)
     }
-    #[cfg(target_arch = "aarch64")]
+    #[cfg(all(target_arch = "aarch64", target_endian = "little"))]
     {
         crate::arch::aarch64::memchr::count_raw(needle, start, end)
     }
     #[cfg(not(any(
         target_arch = "x86_64",
         target_arch = "wasm32",
-        target_arch = "aarch64"
+        all(target_arch = "aarch64", target_endian = "little")
     )))]
     {
         crate::arch::all::memchr::One::new(needle).count_raw(start, end)
