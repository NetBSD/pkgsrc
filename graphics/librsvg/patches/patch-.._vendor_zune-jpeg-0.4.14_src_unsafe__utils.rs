$NetBSD: patch-.._vendor_zune-jpeg-0.4.14_src_unsafe__utils.rs,v 1.1 2025/09/23 11:12:17 adam Exp $

Don't try to do neon / SIMD on big-endian aarch64.

--- ../vendor/zune-jpeg-0.4.14/src/unsafe_utils.rs.orig	2025-02-15 21:57:52.824169081 +0000
+++ ../vendor/zune-jpeg-0.4.14/src/unsafe_utils.rs
@@ -1,4 +1,4 @@
 #[cfg(all(feature = "x86", any(target_arch = "x86", target_arch = "x86_64")))]
 pub use crate::unsafe_utils_avx2::*;
-#[cfg(all(feature = "neon", target_arch = "aarch64"))]
+#[cfg(all(feature = "neon", target_arch = "aarch64", target_endian = "little"))]
 pub use crate::unsafe_utils_neon::*;
