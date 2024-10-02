$NetBSD: patch-.._vendor_memchr-2.7.4_src_vector.rs,v 1.1 2024/10/02 17:49:02 he Exp $

Make this build on big-endian aarch64.

--- ../vendor/memchr-2.7.4/src/vector.rs.orig	2024-10-01 22:43:45.510956667 +0000
+++ ../vendor/memchr-2.7.4/src/vector.rs
@@ -289,7 +289,7 @@ mod x86avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64neon {
     use core::arch::aarch64::*;
 
