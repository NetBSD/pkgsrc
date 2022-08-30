$NetBSD: patch-vendor_libc-0.2.123_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2022/08/30 19:22:17 he Exp $

Copy execinfo function definitions from openbsd's mod.rs.

--- vendor/libc-0.2.123/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2022-06-27 15:22:31.000000000 +0000
+++ vendor/libc-0.2.123/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2784,6 +2784,22 @@ extern "C" {
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
