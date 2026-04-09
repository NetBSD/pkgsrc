$NetBSD: patch-.._vendor_metrics-0.24.0_src_recorder_mod.rs,v 1.1 2026/04/09 08:56:34 wiz Exp $

Fix build with rust 1.94.
https://github.com/metrics-rs/metrics/commit/1e392834c2992236772f9f215b8d3c4bc7135076

--- ../vendor/metrics-0.24.0/src/recorder/mod.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/metrics-0.24.0/src/recorder/mod.rs
@@ -145,12 +139,19 @@ impl<'a> LocalRecorderGuard<'a> {
 
 impl<'a> LocalRecorderGuard<'a> {
     /// Creates a new `LocalRecorderGuard` and sets the thread-local recorder.
-    fn new(recorder: &'a dyn Recorder) -> Self {
-        // SAFETY: While we take a lifetime-less pointer to the given reference, the reference we
-        // derive _from_ the pointer is given the same lifetime of the reference
-        // used to construct the guard -- captured in the guard type itself --
-        // and so derived references never outlive the source reference.
-        let recorder_ptr = unsafe { NonNull::new_unchecked(recorder as *const _ as *mut _) };
+    fn new(recorder: &'a (dyn Recorder + 'a)) -> Self {
+        // SAFETY: We extend `'a` to `'static` to satisfy the signature of `LOCAL_RECORDER`, which
+        // has an implied `'static` bound on `dyn Recorder`. We enforce that all usages of `LOCAL_RECORDER`
+        // are limited to `'a` as we mediate its access entirely through `LocalRecorderGuard<'a>`.
+        let recorder_ptr = unsafe {
+            std::mem::transmute::<*const (dyn Recorder + 'a), *mut (dyn Recorder + 'static)>(
+                recorder as &'a (dyn Recorder + 'a),
+            )
+        };
+        // SAFETY: While we take a lifetime-less pointer to the given reference, the reference we derive _from_ the
+        // pointer is given the same lifetime of the reference used to construct the guard -- captured in the guard type
+        // itself -- and so derived references never outlive the source reference.
+        let recorder_ptr = unsafe { NonNull::new_unchecked(recorder_ptr) };
 
         let prev_recorder =
             LOCAL_RECORDER.with(|local_recorder| local_recorder.replace(Some(recorder_ptr)));
