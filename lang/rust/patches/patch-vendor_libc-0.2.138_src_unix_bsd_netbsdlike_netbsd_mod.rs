$NetBSD: patch-vendor_libc-0.2.138_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.3 2023/10/10 13:12:33 pin Exp $

Add execinfo / backtrace stuff for NetBSD, and handle NetBSD/mips
and NetBSD/riscv64.

--- vendor/libc-0.2.138/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2023-04-16 23:32:41.000000000 +0000
+++ vendor/libc-0.2.138/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3049,6 +3049,22 @@ extern "C" {
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
@@ -3068,7 +3084,15 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "mips")] {
+	mod mips;
+	pub use self::mips::*;
+    } else if #[cfg(target_arch = "riscv64")] {
+        mod riscv64;
+        pub use self::riscv64:*;
     } else {
-        // Unknown target_arch
+        // Unknown target_arch, this should error out
+	mod unknown;
+	pub use self::unknown::*;
     }
 }
