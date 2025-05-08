$NetBSD: patch-.._vendor_memchr-2.7.4_src_vector.rs,v 1.1 2025/05/08 06:30:27 pin Exp $

Do not try to use neon on big-endian aarch64.

--- ../vendor/memchr-2.7.4/src/vector.rs.orig	2025-02-15 09:24:32.108467529 +0000
+++ ../vendor/memchr-2.7.4/src/vector.rs
@@ -293,7 +293,7 @@ mod x86avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64neon {
     use core::arch::aarch64::*;
 
