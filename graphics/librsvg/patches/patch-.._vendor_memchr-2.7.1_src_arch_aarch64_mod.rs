$NetBSD: patch-.._vendor_memchr-2.7.1_src_arch_aarch64_mod.rs,v 1.1 2025/02/15 23:41:46 he Exp $

Do not try to use neon / SIMD on big-endian aarch64.

--- ../vendor/memchr-2.7.1/src/arch/aarch64/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/memchr-2.7.1/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
