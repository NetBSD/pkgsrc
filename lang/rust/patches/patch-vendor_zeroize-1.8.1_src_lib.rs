$NetBSD: patch-vendor_zeroize-1.8.1_src_lib.rs,v 1.2 2025/08/25 17:51:14 wiz Exp $

Don't try to use the NEON-specific module in big-endian mode.

--- vendor/zeroize-1.8.1/src/lib.rs.orig	2025-04-06 07:17:23.864281079 +0000
+++ vendor/zeroize-1.8.1/src/lib.rs
@@ -245,7 +245,7 @@ extern crate std;
 #[cfg(feature = "zeroize_derive")]
 pub use zeroize_derive::{Zeroize, ZeroizeOnDrop};
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64;
 #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
 mod x86;
