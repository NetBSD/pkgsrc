$NetBSD: patch-vendor_libc-0.2.149_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2024/03/03 14:53:33 he Exp $

Add support for NetBSD/riscv64 and MetBSD/mipsel.

Add fix to cpuid_t definition by applying
  https://github.com/rust-lang/libc/pull/3386

--- vendor/libc-0.2.149/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2024-01-08 07:25:50.125422539 +0000
+++ vendor/libc-0.2.149/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -10,7 +10,7 @@ type __pthread_spin_t = __cpu_simple_loc
 pub type vm_size_t = ::uintptr_t; // FIXME: deprecated since long time
 pub type lwpid_t = ::c_uint;
 pub type shmatt_t = ::c_uint;
-pub type cpuid_t = u64;
+pub type cpuid_t = ::c_ulong;
 pub type cpuset_t = _cpuset;
 pub type pthread_spin_t = ::c_uchar;
 pub type timer_t = ::c_int;
@@ -3208,6 +3208,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "mips")] {
+        mod mips;
+        pub use self::mips::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64::*;
     } else {
         // Unknown target_arch
     }
