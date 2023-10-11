$NetBSD: patch-.._vendor_libc-0.2.142_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1 2023/10/11 11:44:22 pin Exp $

https://github.com/rust-lang/libc/pull/3368

--- ../vendor/libc-0.2.142/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/libc-0.2.142/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -1852,6 +1852,9 @@ pub const MNT_NODEVMTIME: ::c_int = 0x40
 pub const MNT_SOFTDEP: ::c_int = 0x80000000;
 pub const MNT_POSIX1EACLS: ::c_int = 0x00000800;
 pub const MNT_ACLS: ::c_int = MNT_POSIX1EACLS;
+pub const MNT_WAIT: ::c_int = 1;
+pub const MNT_NOWAIT: ::c_int = 2;
+pub const MNT_LAZY: ::c_int = 3;
 
 //<sys/timex.h>
 pub const NTP_API: ::c_int = 4;
@@ -3153,6 +3156,38 @@ extern "C" {
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
+    pub fn backtrace_symbols_fd_fmt(
+        addrlist: *const *mut ::c_void,
+        len: ::size_t,
+        fd: ::c_int,
+        fmt: *const ::c_char,
+    ) -> ::c_int;
+}
+
+cfg_if! {
+    if #[cfg(libc_union)] {
+        extern {
+            // these functions use statvfs:
+            pub fn getmntinfo(mntbufp: *mut *mut ::statvfs, flags: ::c_int) -> ::c_int;
+            pub fn getvfsstat(buf: *mut statvfs, bufsize: ::size_t, flags: ::c_int) -> ::c_int;
+        }
+    }
+}
+
 cfg_if! {
     if #[cfg(target_arch = "aarch64")] {
         mod aarch64;
