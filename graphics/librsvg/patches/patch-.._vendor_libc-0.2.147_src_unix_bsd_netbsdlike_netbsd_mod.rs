$NetBSD: patch-.._vendor_libc-0.2.147_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2023/09/09 20:43:42 wiz Exp $

Replicate from main rust package to get riscv64 support.

--- ../vendor/libc-0.2.147/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/libc-0.2.147/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3130,6 +3130,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64::*;
     } else {
         // Unknown target_arch
     }
