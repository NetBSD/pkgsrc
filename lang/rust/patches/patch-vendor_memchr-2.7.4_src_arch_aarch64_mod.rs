$NetBSD: patch-vendor_memchr-2.7.4_src_arch_aarch64_mod.rs,v 1.1 2024/11/24 16:13:43 he Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- vendor/memchr-2.7.4/src/arch/aarch64/mod.rs.orig	2024-09-22 19:17:13.167426584 +0000
+++ vendor/memchr-2.7.4/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
