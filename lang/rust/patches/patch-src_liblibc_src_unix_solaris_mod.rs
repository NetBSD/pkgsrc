$NetBSD: patch-src_liblibc_src_unix_solaris_mod.rs,v 1.4 2018/09/14 10:04:43 jperkin Exp $

Add temporary upstream fixes for SunOS.

--- src/liblibc/src/unix/solaris/mod.rs.orig	2018-09-11 03:38:01.000000000 +0000
+++ src/liblibc/src/unix/solaris/mod.rs
@@ -692,6 +692,8 @@ pub const EOWNERDEAD: ::c_int = 58;
 pub const ENOTRECOVERABLE: ::c_int = 59;
 pub const ENOSTR: ::c_int = 60;
 pub const ENODATA: ::c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: ::c_int = ::ENODATA;
 pub const ETIME: ::c_int = 62;
 pub const ENOSR: ::c_int = 63;
 pub const ENONET: ::c_int = 64;
