$NetBSD: patch-vendor_libc-0.2.177_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2026/04/02 19:06:34 wiz Exp $

Use __pthread_spin_t to define pthread_spin_t, not c_uchar which
isn't universally this type on the various NetBSD targets.

Also add m68k target.

--- vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2026-02-11 07:30:54.000000000 +0000
+++ vendor/libc-0.2.177/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -15,7 +15,7 @@ pub type lwpid_t = c_uint;
 pub type shmatt_t = c_uint;
 pub type cpuid_t = c_ulong;
 pub type cpuset_t = _cpuset;
-pub type pthread_spin_t = c_uchar;
+pub type pthread_spin_t = __pthread_spin_t;
 pub type timer_t = c_int;
 
 // elf.h
@@ -3001,6 +3001,9 @@ cfg_if! {
     } else if #[cfg(target_arch = "riscv64")] {
         mod riscv64;
         pub use self::riscv64::*;
+    } else if #[cfg(target_arch = "m68k")] {
+        mod m68k;
+        pub use self::m68k::*;
     } else {
         // Unknown target_arch
     }
