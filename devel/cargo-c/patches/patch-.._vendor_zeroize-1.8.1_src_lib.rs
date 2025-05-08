$NetBSD: patch-.._vendor_zeroize-1.8.1_src_lib.rs,v 1.1 2025/05/08 06:30:27 pin Exp $

Do not try to use neon on big-endian aarch64.

--- ../vendor/zeroize-1.8.1/src/lib.rs.orig	2025-02-17 09:10:19.704961007 +0000
+++ ../vendor/zeroize-1.8.1/src/lib.rs
@@ -245,7 +245,7 @@ extern crate std;
 #[cfg(feature = "zeroize_derive")]
 pub use zeroize_derive::{Zeroize, ZeroizeOnDrop};
 
-#[cfg(target_arch = "aarch64")]
+#[cfg(all(target_arch = "aarch64", target_endian = "little"))]
 mod aarch64;
 #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
 mod x86;
