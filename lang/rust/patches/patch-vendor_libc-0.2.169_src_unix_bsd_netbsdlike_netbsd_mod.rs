$NetBSD: patch-vendor_libc-0.2.169_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.2 2025/08/25 17:51:12 wiz Exp $

Apply https://github.com/rust-lang/libc/pull/4265/files
to fix getmntinfo() from rust.

--- vendor/libc-0.2.169/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2025-02-14 14:04:45.438043897 +0000
+++ vendor/libc-0.2.169/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2850,6 +2850,7 @@ extern "C" {
         hint: *const c_void,
     ) -> c_int;
 
+    #[link_name = "__getmntinfo13"]
     pub fn getmntinfo(mntbufp: *mut *mut crate::statvfs, flags: c_int) -> c_int;
     pub fn getvfsstat(buf: *mut statvfs, bufsize: size_t, flags: c_int) -> c_int;
 }
