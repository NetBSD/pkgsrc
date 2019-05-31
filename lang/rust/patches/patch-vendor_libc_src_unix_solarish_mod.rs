$NetBSD: patch-vendor_libc_src_unix_solarish_mod.rs,v 1.1 2019/05/31 14:11:23 jperkin Exp $

Fix xattr build.

--- vendor/libc/src/unix/solarish/mod.rs.orig	2019-05-20 13:47:24.000000000 +0000
+++ vendor/libc/src/unix/solarish/mod.rs
@@ -981,6 +981,8 @@ pub const EOWNERDEAD: ::c_int = 58;
 pub const ENOTRECOVERABLE: ::c_int = 59;
 pub const ENOSTR: ::c_int = 60;
 pub const ENODATA: ::c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: ::c_int = 62;
 pub const ENOSR: ::c_int = 63;
 pub const ENONET: ::c_int = 64;
