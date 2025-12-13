$NetBSD: patch-libc.rs,v 1.1 2025/12/13 17:47:21 vins Exp $

Add missing definitions required on SunOS.

--- libc-0.2.177/src/unix/solarish/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ libc-0.2.177/src/unix/solarish/mod.rs
@@ -2390,6 +2390,12 @@ const NEWDEV: c_int = 1;
 // sys/sendfile.h
 pub const SFV_FD_SELF: c_int = -2;
 
+// sys/unistd.h
+pub const _CS_PATH: c_int = 65;
+
+// sys/statvfs.h
+pub const MNT_LOCAL: c_int = 0x00001000;
+
 const fn _CMSG_HDR_ALIGN(p: usize) -> usize {
     (p + _CMSG_HDR_ALIGNMENT - 1) & !(_CMSG_HDR_ALIGNMENT - 1)
 }
@@ -2756,6 +2762,7 @@ extern "C" {
         addrlen: *mut crate::socklen_t,
     ) -> ssize_t;
     pub fn mkstemps(template: *mut c_char, suffixlen: c_int) -> c_int;
+    pub fn mkostemp(template: *mut c_char, flags: c_int) -> c_int;
     pub fn futimesat(fd: c_int, path: *const c_char, times: *const crate::timeval) -> c_int;
     pub fn futimens(dirfd: c_int, times: *const crate::timespec) -> c_int;
     pub fn utimensat(
