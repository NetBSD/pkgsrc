$NetBSD: patch-.._vendor_memchr-2.7.4_src_arch_aarch64_mod.rs,v 1.1 2024/10/02 17:49:02 he Exp $

Make this build on big-endian aarch64.

--- ../vendor/memchr-2.7.4/src/arch/aarch64/mod.rs.orig	2024-10-01 22:42:20.721140485 +0000
+++ ../vendor/memchr-2.7.4/src/arch/aarch64/mod.rs
@@ -2,6 +2,8 @@
 Vector algorithms for the `aarch64` target.
 */
 
+#[cfg(target_endian = "little")]
 pub mod neon;
 
+#[cfg(target_endian = "little")]
 pub(crate) mod memchr;
