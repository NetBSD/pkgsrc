$NetBSD: patch-library_std_src_sys_unix_thread__parker_netbsd.rs,v 1.1 2023/01/23 18:49:04 he Exp $

Try to cast to make this build, to avoid

74 |                 tv_nsec: dur.subsec_nanos().into(),
   |                          ^^^^^^^^^^^^^^^^^^ ---- required by a bound introduced by this call
   |                          |
   |                          the trait `core::convert::From<u32>` is not implemented for `i32`
...
   = note: required for `u32` to implement `core::convert::Into<i32>`

For more information about this error, try `rustc --explain E0277`.

Also, try to unbreak 32-bit ports ... again.

--- library/std/src/sys/unix/thread_parker/netbsd.rs.orig	2022-11-02 14:36:24.000000000 +0000
+++ library/std/src/sys/unix/thread_parker/netbsd.rs
@@ -2,7 +2,7 @@ use crate::ffi::{c_int, c_void};
 use crate::pin::Pin;
 use crate::ptr::{null, null_mut};
 use crate::sync::atomic::{
-    AtomicU64,
+    AtomicU32,
     Ordering::{Acquire, Relaxed, Release},
 };
 use crate::time::Duration;
@@ -24,19 +24,19 @@ extern "C" {
 ///
 /// Zero cannot be a valid LWP id, since it is used as empty value for the unpark
 /// argument in _lwp_park.
-const EMPTY: u64 = 0;
+const EMPTY: u32 = 0;
 /// The token is available. Do not park anymore.
-const NOTIFIED: u64 = u64::MAX;
+const NOTIFIED: u32 = u32::MAX;
 
 pub struct Parker {
     /// The parker state. Contains either one of the two state values above or the LWP
     /// id of the parked thread.
-    state: AtomicU64,
+    state: AtomicU32,
 }
 
 impl Parker {
     pub unsafe fn new(parker: *mut Parker) {
-        parker.write(Parker { state: AtomicU64::new(EMPTY) })
+        parker.write(Parker { state: AtomicU32::new(EMPTY) })
     }
 
     // Does not actually need `unsafe` or `Pin`, but the pthread implementation does.
@@ -44,7 +44,7 @@ impl Parker {
         // If the token has already been made available, we can skip
         // a bit of work, so check for it here.
         if self.state.load(Acquire) != NOTIFIED {
-            let parked = _lwp_self() as u64;
+            let parked = _lwp_self();
             let hint = self.state.as_mut_ptr().cast();
             if self.state.compare_exchange(EMPTY, parked, Relaxed, Acquire).is_ok() {
                 // Loop to guard against spurious wakeups.
@@ -65,13 +65,13 @@ impl Parker {
     // Does not actually need `unsafe` or `Pin`, but the pthread implementation does.
     pub unsafe fn park_timeout(self: Pin<&Self>, dur: Duration) {
         if self.state.load(Acquire) != NOTIFIED {
-            let parked = _lwp_self() as u64;
+            let parked = _lwp_self();
             let hint = self.state.as_mut_ptr().cast();
             let mut timeout = timespec {
                 // Saturate so that the operation will definitely time out
                 // (even if it is after the heat death of the universe).
                 tv_sec: dur.as_secs().try_into().ok().unwrap_or(time_t::MAX),
-                tv_nsec: dur.subsec_nanos().into(),
+                tv_nsec: (dur.subsec_nanos() as libc::c_long).into(),
             };
 
             if self.state.compare_exchange(EMPTY, parked, Relaxed, Acquire).is_ok() {
