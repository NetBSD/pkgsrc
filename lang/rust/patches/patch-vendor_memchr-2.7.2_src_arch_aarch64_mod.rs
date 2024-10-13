$NetBSD: patch-vendor_memchr-2.7.2_src_arch_aarch64_mod.rs,v 1.1 2024/10/13 19:04:40 he Exp $

Only use neon extension on little-endian aarch64.
Ref. https://github.com/rust-lang/rust/issues/129819

--- vendor/memchr-2.7.2/src/arch/aarch64/mod.rs.orig	2024-09-01 09:05:35.656376678 +0000
+++ vendor/memchr-2.7.2/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
