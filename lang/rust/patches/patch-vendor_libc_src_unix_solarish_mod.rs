$NetBSD: patch-vendor_libc_src_unix_solarish_mod.rs,v 1.2 2021/04/19 17:08:09 he Exp $

Fix xattr build.

--- vendor/libc/src/unix/solarish/mod.rs.orig	2021-02-10 18:18:38.000000000 +0000
+++ vendor/libc/src/unix/solarish/mod.rs
@@ -1177,6 +1177,8 @@ pub const EOWNERDEAD: ::c_int = 58;
 pub const ENOTRECOVERABLE: ::c_int = 59;
 pub const ENOSTR: ::c_int = 60;
 pub const ENODATA: ::c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: ::c_int = 62;
 pub const ENOSR: ::c_int = 63;
 pub const ENONET: ::c_int = 64;
