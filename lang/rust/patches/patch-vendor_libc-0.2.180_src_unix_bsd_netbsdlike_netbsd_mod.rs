$NetBSD: patch-vendor_libc-0.2.180_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2026/05/07 13:16:15 wiz Exp $

Add m68k target.

--- vendor/libc-0.2.180/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2026-04-16 15:19:35.521206884 +0000
+++ vendor/libc-0.2.180/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2442,6 +2442,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "riscv64")] {
         mod riscv64;
         pub use self::riscv64::*;
+    } else if #[cfg(target_arch = "m68k")] {
+        mod m68k;
+        pub use self::m68k::*;
     } else {
         // Unknown target_arch
     }
