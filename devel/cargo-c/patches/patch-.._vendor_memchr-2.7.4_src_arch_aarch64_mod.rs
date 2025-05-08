$NetBSD: patch-.._vendor_memchr-2.7.4_src_arch_aarch64_mod.rs,v 1.1 2025/05/08 06:30:27 pin Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/memchr-2.7.4/src/arch/aarch64/mod.rs.orig	2025-02-15 09:14:20.982023231 +0000
+++ ../vendor/memchr-2.7.4/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
