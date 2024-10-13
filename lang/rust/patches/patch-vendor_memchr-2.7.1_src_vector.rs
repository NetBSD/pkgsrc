$NetBSD: patch-vendor_memchr-2.7.1_src_vector.rs,v 1.1 2024/10/13 19:04:40 he Exp $

Avoid using neon on big-endian aarch64.

--- vendor/memchr-2.7.1/src/vector.rs.orig	2024-09-29 15:24:01.478487808 +0000
+++ vendor/memchr-2.7.1/src/vector.rs
@@ -293,7 +293,7 @@ mod x86avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64neon {
     use core::arch::aarch64::*;
 
