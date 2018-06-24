$NetBSD: patch-src_vendor_libc_src_unix_solaris_mod.rs,v 1.1 2018/06/24 08:05:26 ryoon Exp $

Work around build issue in xattr.
https://github.com/Stebalien/xattr/issues/18

--- src/vendor/libc/src/unix/solaris/mod.rs.orig	2018-06-19 05:52:22.000000000 +0000
+++ src/vendor/libc/src/unix/solaris/mod.rs
@@ -692,6 +692,8 @@ pub const EOWNERDEAD: ::c_int = 58;
 pub const ENOTRECOVERABLE: ::c_int = 59;
 pub const ENOSTR: ::c_int = 60;
 pub const ENODATA: ::c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: ::c_int = 62;
 pub const ENOSR: ::c_int = 63;
 pub const ENONET: ::c_int = 64;
