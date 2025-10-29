$NetBSD: patch-.._vendor_memchr-2.7.6_src_vector.rs,v 1.1 2025/10/29 07:17:59 pin Exp $

Make this build on big-endian aarch64.

--- ../vendor/memchr-2.7.6/src/vector.rs.orig	2025-08-02 13:25:30.811977578 +0000
+++ ../vendor/memchr-2.7.6/src/vector.rs
@@ -289,7 +289,7 @@ mod x86avx2 {
     }
 }
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64neon {
     use core::arch::aarch64::*;
 
