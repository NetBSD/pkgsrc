$NetBSD: patch-src_vendor_libc_src_unix_solaris_mod.rs,v 1.2 2018/08/09 17:04:03 jperkin Exp $

Work around build issue in xattr.
https://github.com/Stebalien/xattr/issues/18

--- src/vendor/libc/src/unix/solaris/mod.rs.orig	2018-07-30 23:30:25.000000000 +0000
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
@@ -1208,7 +1210,7 @@ pub const EPOLLET: ::c_int = 0x80000000;
 pub const EPOLLRDHUP: ::c_int = 0x2000;
 pub const EPOLLEXCLUSIVE: ::c_int = 0x10000000;
 pub const EPOLLONESHOT: ::c_int = 0x40000000;
-pub const EPOLL_CLOEXEC: ::c_int = 0x02000000;
+pub const EPOLL_CLOEXEC: ::c_int = 0x80000;
 pub const EPOLL_CTL_ADD: ::c_int = 1;
 pub const EPOLL_CTL_MOD: ::c_int = 3;
 pub const EPOLL_CTL_DEL: ::c_int = 2;
