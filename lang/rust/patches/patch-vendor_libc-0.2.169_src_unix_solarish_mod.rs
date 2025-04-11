$NetBSD: patch-vendor_libc-0.2.169_src_unix_solarish_mod.rs,v 1.2 2025/04/11 10:03:22 jperkin Exp $

Fix xattr build.

--- vendor/libc-0.2.169/src/unix/solarish/mod.rs.orig	2024-08-29 18:03:17.866520790 +0000
+++ vendor/libc-0.2.169/src/unix/solarish/mod.rs
@@ -1421,6 +1421,8 @@ pub const EOWNERDEAD: c_int = 58;
 pub const ENOTRECOVERABLE: c_int = 59;
 pub const ENOSTR: c_int = 60;
 pub const ENODATA: c_int = 61;
+// This is not supported but is required for xattr
+pub const ENOATTR: c_int = ENODATA;
 pub const ETIME: c_int = 62;
 pub const ENOSR: c_int = 63;
 pub const ENONET: c_int = 64;
