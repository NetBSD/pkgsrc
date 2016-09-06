$NetBSD: patch-src_liblibc_src_unix_solaris_mod.rs,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Additional Solarish support.

--- src/liblibc/src/unix/solaris/mod.rs.orig	2016-08-16 01:54:44.000000000 +0000
+++ src/liblibc/src/unix/solaris/mod.rs
@@ -487,9 +487,13 @@ pub const SIGSEGV: ::c_int = 11;
 pub const SIGPIPE: ::c_int = 13;
 pub const SIGALRM: ::c_int = 14;
 pub const SIGTERM: ::c_int = 15;
+pub const SIGWINCH: ::c_int = 20;
 
 pub const WNOHANG: ::c_int = 0x40;
 
+pub const RTLD_NOW: ::c_int = 0x2;
+pub const RTLD_DEFAULT: *mut ::c_void = -2isize as *mut ::c_void;
+
 pub const PROT_NONE: ::c_int = 0;
 pub const PROT_READ: ::c_int = 1;
 pub const PROT_WRITE: ::c_int = 2;
@@ -707,8 +711,8 @@ pub const IP_TTL: ::c_int = 4;
 pub const IP_HDRINCL: ::c_int = 2;
 pub const IP_ADD_MEMBERSHIP: ::c_int = 19;
 pub const IP_DROP_MEMBERSHIP: ::c_int = 20;
-pub const IPV6_JOIN_GROUP: ::c_int = 9;
-pub const IPV6_LEAVE_GROUP: ::c_int = 10;
+pub const IPV6_ADD_MEMBERSHIP: ::c_int = 9;
+pub const IPV6_DROP_MEMBERSHIP: ::c_int = 10;
 
 pub const TCP_NODELAY: ::c_int = 1;
 pub const TCP_KEEPIDLE: ::c_int = 34;
