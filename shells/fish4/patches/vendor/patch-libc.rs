$NetBSD: patch-libc.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

Provide a declaration for mkostemp and strftime on SunOS.

--- libc-0.2.172/src/unix/solarish/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ libc-0.2.172/src/unix/solarish/mod.rs
@@ -2831,6 +2854,7 @@ extern "C" {
         addrlen: *mut crate::socklen_t,
     ) -> ssize_t;
     pub fn mkstemps(template: *mut c_char, suffixlen: c_int) -> c_int;
+    pub fn mkostemp(template: *mut c_char, flags: c_int) -> c_int;
     pub fn futimesat(fd: c_int, path: *const c_char, times: *const crate::timeval) -> c_int;
     pub fn futimens(dirfd: c_int, times: *const crate::timespec) -> c_int;
     pub fn utimensat(
@@ -3148,6 +3172,13 @@ extern "C" {
         validity: *mut c_uint,
     ) -> c_int;
 
+    pub fn strftime(
+        arg1: *mut c_char,
+        arg2: size_t,
+        arg3: *const c_char,
+        arg4: *const tm,
+    ) -> size_t; 
+
     pub fn strsep(string: *mut *mut c_char, delim: *const c_char) -> *mut c_char;
 
     pub fn getisax(array: *mut u32, n: c_uint) -> c_uint;
