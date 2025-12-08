$NetBSD: patch-.._vendor_memchr-2.7.6_src_arch_aarch64_mod.rs,v 1.1 2025/12/08 12:40:16 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/memchr-2.7.6/src/arch/aarch64/mod.rs.orig	2025-02-15 20:46:55.895217561 +0000
+++ ../vendor/memchr-2.7.6/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
