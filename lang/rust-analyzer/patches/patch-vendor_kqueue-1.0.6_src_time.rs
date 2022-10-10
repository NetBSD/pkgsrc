$NetBSD: patch-vendor_kqueue-1.0.6_src_time.rs,v 1.1 2022/10/10 08:08:28 he Exp $

Use the timespec component types instead of hardcoding int lengths.

--- vendor/kqueue-1.0.6/src/time.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ vendor/kqueue-1.0.6/src/time.rs
@@ -1,32 +1,11 @@
+use libc::time_t;
+use libc::c_long;
 use libc::timespec;
 use std::time::Duration;
 
-#[cfg(not(all(
-    any(target_os = "freebsd", target_os = "macos"),
-    any(target_arch = "x86", target_arch = "powerpc")
-)))]
 pub(crate) fn duration_to_timespec(d: Duration) -> timespec {
-    let tv_sec = d.as_secs() as i64;
-    let tv_nsec = d.subsec_nanos() as i64;
-
-    if tv_sec.is_negative() {
-        panic!("Duration seconds is negative");
-    }
-
-    if tv_nsec.is_negative() {
-        panic!("Duration nsecs is negative");
-    }
-
-    timespec { tv_sec, tv_nsec }
-}
-
-#[cfg(all(
-    any(target_os = "freebsd", target_os = "macos"),
-    any(target_arch = "x86", target_arch = "powerpc")
-))]
-pub(crate) fn duration_to_timespec(d: Duration) -> timespec {
-    let tv_sec = d.as_secs() as i32;
-    let tv_nsec = d.subsec_nanos() as i32;
+    let tv_sec = d.as_secs() as time_t;
+    let tv_nsec = d.subsec_nanos() as c_long;
 
     if tv_sec.is_negative() {
         panic!("Duration seconds is negative");
