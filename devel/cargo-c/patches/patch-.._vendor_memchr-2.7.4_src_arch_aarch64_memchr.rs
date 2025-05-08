$NetBSD: patch-.._vendor_memchr-2.7.4_src_arch_aarch64_memchr.rs,v 1.1 2025/05/08 06:30:27 pin Exp $

Do not try to use neon on big-endian aarch64.

--- ../vendor/memchr-2.7.4/src/arch/aarch64/memchr.rs.orig	2025-02-15 09:11:32.497322345 +0000
+++ ../vendor/memchr-2.7.4/src/arch/aarch64/memchr.rs
@@ -8,7 +8,7 @@ available for `aarch64` targets.)
 
 macro_rules! defraw {
     ($ty:ident, $find:ident, $start:ident, $end:ident, $($needles:ident),+) => {{
-        #[cfg(target_feature = "neon")]
+        #[cfg(all(target_feature = "neon", target_endian = "little"))]
         {
             use crate::arch::aarch64::neon::memchr::$ty;
 
@@ -19,7 +19,7 @@ macro_rules! defraw {
             // enabled.
             $ty::new_unchecked($($needles),+).$find($start, $end)
         }
-        #[cfg(not(target_feature = "neon"))]
+        #[cfg(not(all(target_feature = "neon", target_endian = "little")))]
         {
             use crate::arch::all::memchr::$ty;
 
