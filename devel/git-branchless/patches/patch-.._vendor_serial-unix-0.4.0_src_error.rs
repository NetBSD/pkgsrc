$NetBSD: patch-.._vendor_serial-unix-0.4.0_src_error.rs,v 1.1 2023/08/30 08:30:17 pin Exp $

Add bsiegert@ unmerged pull request
https://github.com/dcuddeback/serial-rs/pull/63

--- ../vendor/serial-unix-0.4.0/src/error.rs.orig	2017-07-02 01:20:06.000000000 +0000
+++ ../vendor/serial-unix-0.4.0/src/error.rs
@@ -64,7 +64,7 @@ pub fn errno() -> i32 {
         __dfly_error()
     }
 
-    #[cfg(target_os = "openbsd")]
+    #[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
     unsafe fn errno_location() -> *const c_int {
         extern { fn __errno() -> *const c_int; }
         __errno()
