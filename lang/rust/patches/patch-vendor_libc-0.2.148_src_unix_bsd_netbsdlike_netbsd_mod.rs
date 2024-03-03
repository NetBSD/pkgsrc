$NetBSD: patch-vendor_libc-0.2.148_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2024/03/03 14:53:33 he Exp $

Add entries for execinfo, and support
for NetBSD/mips and NetBSD/riscv64.

--- vendor/libc-0.2.148/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2024-01-06 22:33:33.911876204 +0000
+++ vendor/libc-0.2.148/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -10,7 +10,7 @@ type __pthread_spin_t = __cpu_simple_loc
 pub type vm_size_t = ::uintptr_t; // FIXME: deprecated since long time
 pub type lwpid_t = ::c_uint;
 pub type shmatt_t = ::c_uint;
-pub type cpuid_t = u64;
+pub type cpuid_t = ::c_ulong;
 pub type cpuset_t = _cpuset;
 pub type pthread_spin_t = ::c_uchar;
 pub type timer_t = ::c_int;
@@ -3153,6 +3153,22 @@ extern "C" {
     pub fn kinfo_getvmmap(pid: ::pid_t, cntp: *mut ::size_t) -> *mut kinfo_vmentry;
 }
 
+#[link(name = "execinfo")]
+extern "C" {
+    pub fn backtrace(addrlist: *mut *mut ::c_void, len: ::size_t) -> ::size_t;
+    pub fn backtrace_symbols(addrlist: *const *mut ::c_void, len: ::size_t) -> *mut *mut ::c_char;
+    pub fn backtrace_symbols_fd(
+        addrlist: *const *mut ::c_void,
+        len: ::size_t,
+        fd: ::c_int,
+    ) -> ::c_int;
+    pub fn backtrace_symbols_fmt(
+        addrlist: *const *mut ::c_void,
+        len: ::size_t,
+        fmt: *const ::c_char,
+    ) -> *mut *mut ::c_char;
+}
+
 cfg_if! {
     if #[cfg(target_arch = "aarch64")] {
         mod aarch64;
@@ -3172,6 +3188,12 @@ cfg_if! {
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
