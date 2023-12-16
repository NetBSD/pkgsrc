$NetBSD: patch-vendor_libc-0.2.144_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.2 2023/12/16 11:46:22 he Exp $

Add riscv64 and mips.

--- ../vendor/libc-0.2.144/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/libc-0.2.144/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3172,6 +3172,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64::*;
+    } else if #[cfg(target_arch = "mips")] {
+        mod mips;
+        pub use self::mips::*;
     } else {
         // Unknown target_arch
     }
