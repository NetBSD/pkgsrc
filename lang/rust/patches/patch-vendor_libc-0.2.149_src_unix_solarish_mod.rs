$NetBSD: patch-vendor_libc-0.2.149_src_unix_solarish_mod.rs,v 1.1 2024/03/03 14:53:33 he Exp $

Fix xattr build.

--- vendor/libc-0.2.149/src/unix/solarish/mod.rs.orig	2024-01-08 13:00:15.626503385 +0000
+++ vendor/libc-0.2.149/src/unix/solarish/mod.rs
@@ -1523,6 +1523,8 @@ pub const EOWNERDEAD: ::c_int = 58;
 pub const ENOTRECOVERABLE: ::c_int = 59;
 pub const ENOSTR: ::c_int = 60;
 pub const ENODATA: ::c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: ::c_int = 62;
 pub const ENOSR: ::c_int = 63;
 pub const ENONET: ::c_int = 64;
