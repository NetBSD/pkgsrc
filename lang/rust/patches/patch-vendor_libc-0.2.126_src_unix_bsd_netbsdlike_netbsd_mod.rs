$NetBSD: patch-vendor_libc-0.2.126_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2023/01/23 18:49:04 he Exp $

Replicate patch from un-versioned libc.

--- vendor/libc-0.2.126/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2022-12-12 18:23:58.000000000 +0000
+++ vendor/libc-0.2.126/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2840,7 +2840,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "mips")] {
+	mod mips;
+	pub use self::mips::*;
     } else {
-        // Unknown target_arch
+        // Unknown target_arch, this should error out
+	mod unknown;
+	pub use self::unknown::*;
     }
 }
