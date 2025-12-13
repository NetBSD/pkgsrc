$NetBSD: patch-src_builtins_ulimit.rs,v 1.1 2025/12/13 17:47:21 vins Exp $

Some resource limits are unsupported on SunOS. 

--- src/builtins/ulimit.rs.orig	2025-11-13 12:09:28.000000000 +0000
+++ src/builtins/ulimit.rs
@@ -21,7 +21,7 @@ pub mod limits {
         pub const DATA: libc::c_int = libc::RLIMIT_DATA as _;
         pub const FSIZE: libc::c_int = libc::RLIMIT_FSIZE as _;
         cfg_if!(
-            if #[cfg(cygwin)] {
+            if #[cfg(any(cygwin,illumos))] {
                 pub const MEMLOCK: libc::c_int = -1;
             } else {
                 pub const MEMLOCK: libc::c_int = libc::RLIMIT_MEMLOCK as _;
@@ -31,7 +31,7 @@ pub mod limits {
         pub const STACK: libc::c_int = libc::RLIMIT_STACK as _;
         pub const CPU: libc::c_int = libc::RLIMIT_CPU as _;
         cfg_if!(
-            if #[cfg(cygwin)] {
+            if #[cfg(any(cygwin,illumos))] {
                 pub const NPROC: libc::c_int = -1;
             } else {
                 pub const NPROC: libc::c_int = libc::RLIMIT_NPROC as _;
