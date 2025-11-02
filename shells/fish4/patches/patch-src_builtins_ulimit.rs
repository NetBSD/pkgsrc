$NetBSD: patch-src_builtins_ulimit.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

Builtin ulimit: extract function.

--- src/builtins/ulimit.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/builtins/ulimit.rs
@@ -2,6 +2,7 @@ use std::cmp::Ordering;
 
 use libc::{c_uint, rlim_t, RLIM_INFINITY};
 use nix::errno::Errno;
+use nix::sys::resource::Resource as ResourceEnum;
 use once_cell::sync::Lazy;
 
 use crate::fallback::{fish_wcswidth, wcscasecmp};
@@ -10,22 +11,22 @@ use crate::wutil::perror;
 
 use super::prelude::*;
 
-/// Calls getrlimit.
-fn getrlimit(resource: c_uint) -> Option<(rlim_t, rlim_t)> {
+fn convert_resource(resource: c_uint) -> ResourceEnum {
     let resource: i32 = resource.try_into().unwrap();
-
+    use std::mem::{size_of, transmute};
     // Resource is #[repr(i32)] so this is ok
-    let resource = unsafe { std::mem::transmute::<i32, nix::sys::resource::Resource>(resource) };
-    nix::sys::resource::getrlimit(resource)
+    const _: () = assert!(size_of::<c_uint>() == size_of::<ResourceEnum>());
+    unsafe { transmute(resource) }
+}
+/// Calls getrlimit.
+fn getrlimit(resource: c_uint) -> Option<(rlim_t, rlim_t)> {
+    nix::sys::resource::getrlimit(convert_resource(resource))
         .map_err(|_| perror("getrlimit"))
         .ok()
 }
 
 fn setrlimit(resource: c_uint, rlim_cur: rlim_t, rlim_max: rlim_t) -> Result<(), Errno> {
-    let resource: i32 = resource.try_into().unwrap();
-    // Resource is #[repr(i32)] so this is ok
-    let resource = unsafe { std::mem::transmute::<i32, nix::sys::resource::Resource>(resource) };
-    nix::sys::resource::setrlimit(resource, rlim_cur, rlim_max)
+    nix::sys::resource::setrlimit(convert_resource(resource), rlim_cur, rlim_max)
 }
 
 /// Print the value of the specified resource limit.
