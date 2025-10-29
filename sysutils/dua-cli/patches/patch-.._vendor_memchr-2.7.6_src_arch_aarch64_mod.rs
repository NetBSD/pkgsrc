$NetBSD: patch-.._vendor_memchr-2.7.6_src_arch_aarch64_mod.rs,v 1.1 2025/10/29 07:17:59 pin Exp $

Make this build on big-endian aarch64.

--- ../vendor/memchr-2.7.6/src/arch/aarch64/mod.rs.orig	2025-08-02 10:48:31.136857619 +0000
+++ ../vendor/memchr-2.7.6/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
