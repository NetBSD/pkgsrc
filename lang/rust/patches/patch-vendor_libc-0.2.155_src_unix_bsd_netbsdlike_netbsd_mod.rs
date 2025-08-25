$NetBSD: patch-vendor_libc-0.2.155_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.2 2025/08/25 17:51:12 wiz Exp $

Apply https://github.com/rust-lang/libc/pull/4265/files
to fix getmntinfo() from rust.

--- vendor/libc-0.2.155/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2025-02-14 14:04:45.438043897 +0000
+++ vendor/libc-0.2.155/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -3142,6 +3142,7 @@ cfg_if! {
     if #[cfg(libc_union)] {
         extern {
             // these functions use statvfs:
+            #[link_name = "__getmntinfo13"]
             pub fn getmntinfo(mntbufp: *mut *mut ::statvfs, flags: ::c_int) -> ::c_int;
             pub fn getvfsstat(buf: *mut statvfs, bufsize: ::size_t, flags: ::c_int) -> ::c_int;
         }
