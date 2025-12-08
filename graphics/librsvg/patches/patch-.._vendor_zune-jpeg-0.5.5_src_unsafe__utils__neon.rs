$NetBSD: patch-.._vendor_zune-jpeg-0.5.5_src_unsafe__utils__neon.rs,v 1.1 2025/12/08 12:40:17 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/zune-jpeg-0.5.5/src/unsafe_utils_neon.rs.orig	2025-12-08 12:08:47.494619825 +0000
+++ ../vendor/zune-jpeg-0.5.5/src/unsafe_utils_neon.rs
@@ -6,7 +6,7 @@
  * You can redistribute it or modify it under terms of the MIT, Apache License or Zlib license
  */
 
-#![cfg(all(feature = "neon", target_arch = "aarch64"))]
+#![cfg(all(feature = "neon", target_arch = "aarch64", target_endian = "little"))]
 // TODO can this be extended to armv7
 
 //! This module provides unsafe ways to do some things
