$NetBSD: patch-.._vendor_zune-jpeg-0.4.14_src_unsafe__utils__neon.rs,v 1.1 2025/09/23 11:12:17 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/zune-jpeg-0.4.14/src/unsafe_utils_neon.rs.orig	2025-02-15 22:09:18.837627422 +0000
+++ ../vendor/zune-jpeg-0.4.14/src/unsafe_utils_neon.rs
@@ -6,7 +6,7 @@
  * You can redistribute it or modify it under terms of the MIT, Apache License or Zlib license
  */
 
-#![cfg(target_arch = "aarch64")]
+#![cfg(all(target_arch = "aarch64", target_endian = "little"))]
 // TODO can this be extended to armv7
 
 //! This module provides unsafe ways to do some things
