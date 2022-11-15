$NetBSD: patch-vendor_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.4 2022/11/15 23:11:14 he Exp $

Copy execinfo function definitions from openbsd's mod.rs.

--- vendor/libc/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2022-05-10 20:59:35.217463943 +0000
+++ vendor/libc/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2821,6 +2821,22 @@ extern "C" {
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
@@ -2840,6 +2856,12 @@ cfg_if! {
     } else if #[cfg(target_arch = "x86")] {
         mod x86;
         pub use self::x86::*;
+    } else if #[cfg(target_arch = "mips")] {
+        mod mips;
+        pub use self::mips::*;
+    } else if #[cfg(target_arch = "mipsel")] {
+        mod mips;
+        pub use self::mips::*;
     } else {
         // Unknown target_arch
     }
