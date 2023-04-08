$NetBSD: patch-vendor_libc-0.2.135_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2023/04/08 18:18:12 he Exp $

Add use of NetBSD mips target description.

--- vendor/libc-0.2.135/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2023-01-25 01:49:16.000000000 +0000
+++ vendor/libc-0.2.135/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3027,7 +3027,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "mips")] {
+	mod mips;
+	pub use self::mips::*;
     } else {
-        // Unknown target_arch
+        // Unknown target_arch, this should error ouF
+	mod unknown;
+	pub use self::unknown::*;
     }
 }
