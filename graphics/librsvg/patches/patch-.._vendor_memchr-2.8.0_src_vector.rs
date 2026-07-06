$NetBSD: patch-.._vendor_memchr-2.8.0_src_vector.rs,v 1.1 2026/07/06 13:49:07 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/memchr-2.8.0/src/vector.rs.orig	2025-02-15 20:56:52.793849071 +0000
+++ ../vendor/memchr-2.8.0/src/vector.rs
@@ -289,7 +289,7 @@ mod x86avx2 {
     }
 }

-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64neon {
     use core::arch::aarch64::*;
