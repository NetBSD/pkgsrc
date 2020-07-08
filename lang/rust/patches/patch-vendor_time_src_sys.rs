$NetBSD: patch-vendor_time_src_sys.rs,v 1.1 2020/07/08 14:46:14 jperkin Exp $

Support illumos.

--- vendor/time/src/sys.rs.orig	2020-06-01 17:45:25.000000000 +0000
+++ vendor/time/src/sys.rs
@@ -359,7 +359,7 @@ mod inner {
     #[cfg(all(not(target_os = "macos"), not(target_os = "ios")))]
     pub use self::unix::*;
 
-    #[cfg(target_os = "solaris")]
+    #[cfg(any(target_os = "solaris", target_os = "illumos"))]
     extern {
         static timezone: time_t;
         static altzone: time_t;
@@ -390,7 +390,7 @@ mod inner {
         rust_tm.tm_utcoff = utcoff;
     }
 
-    #[cfg(any(target_os = "nacl", target_os = "solaris"))]
+    #[cfg(any(target_os = "nacl", target_os = "solaris", target_os = "illumos"))]
     unsafe fn timegm(tm: *mut libc::tm) -> time_t {
         use std::env::{set_var, var_os, remove_var};
         extern {
@@ -433,7 +433,7 @@ mod inner {
             if libc::localtime_r(&sec, &mut out).is_null() {
                 panic!("localtime_r failed: {}", io::Error::last_os_error());
             }
-            #[cfg(target_os = "solaris")]
+            #[cfg(any(target_os = "solaris", target_os = "illumos"))]
             let gmtoff = {
                 ::tzset();
                 // < 0 means we don't know; assume we're not in DST.
@@ -446,7 +446,7 @@ mod inner {
                     -timezone
                 }
             };
-            #[cfg(not(target_os = "solaris"))]
+            #[cfg(not(any(target_os = "solaris", target_os = "illumos")))]
             let gmtoff = out.tm_gmtoff;
             tm_to_rust_tm(&out, gmtoff as i32, tm);
         }
@@ -455,7 +455,7 @@ mod inner {
     pub fn utc_tm_to_time(rust_tm: &Tm) -> i64 {
         #[cfg(all(target_os = "android", target_pointer_width = "32"))]
         use libc::timegm64 as timegm;
-        #[cfg(not(any(all(target_os = "android", target_pointer_width = "32"), target_os = "nacl", target_os = "solaris")))]
+        #[cfg(not(any(all(target_os = "android", target_pointer_width = "32"), target_os = "nacl", target_os = "solaris", target_os = "illumos")))]
         use libc::timegm;
 
         let mut tm = unsafe { mem::zeroed() };
