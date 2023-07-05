$NetBSD: patch-vendor_libc-0.2.144_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2023/07/05 20:33:42 he Exp $

Add riscv64.

--- ../vendor/libc-0.2.144/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/libc-0.2.144/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2807,6 +2807,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64::*;
     } else {
         // Unknown target_arch
     }
