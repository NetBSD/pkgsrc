$NetBSD: patch-vendor_kqueue_src_time.rs,v 1.2 2023/01/23 18:49:04 he Exp $

Use the timespec component types instead of hardcoding int lengths.
...except Linux has a quirk.

--- vendor/kqueue/src/time.rs.orig	2022-09-19 15:35:02.000000000 +0000
+++ vendor/kqueue/src/time.rs
@@ -1,32 +1,15 @@
-use libc::timespec;
+use libc::{timespec, time_t, c_long};
 use std::time::Duration;
 
-#[cfg(not(all(
-    any(target_os = "freebsd", target_os = "macos"),
-    any(target_arch = "x86", target_arch = "powerpc")
-)))]
-pub(crate) fn duration_to_timespec(d: Duration) -> timespec {
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
+// Linux x32 compatibility, ref. libc/src/unix/mod.rs
+#[cfg(all(target_arch = "x86_64", target_pointer_width = "32"))]
+type NSec = i64;
+#[cfg(not(all(target_arch = "x86_64", target_pointer_width = "32")))]
+type NSec = c_long;
 
-#[cfg(all(
-    any(target_os = "freebsd", target_os = "macos"),
-    any(target_arch = "x86", target_arch = "powerpc")
-))]
 pub(crate) fn duration_to_timespec(d: Duration) -> timespec {
-    let tv_sec = d.as_secs() as i32;
-    let tv_nsec = d.subsec_nanos() as i32;
+    let tv_sec = d.as_secs() as time_t;
+    let tv_nsec = d.subsec_nanos() as NSec;
 
     if tv_sec.is_negative() {
         panic!("Duration seconds is negative");
