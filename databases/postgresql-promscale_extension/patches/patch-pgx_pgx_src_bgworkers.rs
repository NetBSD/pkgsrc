$NetBSD: patch-pgx_pgx_src_bgworkers.rs,v 1.1 2021/08/25 11:06:28 tnn Exp $

Fix build on ARM (signed char assumptions)

--- pgx/pgx/src/bgworkers.rs.orig	2021-04-14 16:14:29.000000000 +0000
+++ pgx/pgx/src/bgworkers.rs
@@ -10,6 +10,7 @@ use std::ffi::CStr;
 use std::ffi::CString;
 use std::sync::atomic::{AtomicBool, Ordering};
 use std::time::Duration;
+use std::os::raw::c_char;
 
 pub static mut PREV_SHMEM_STARTUP_HOOK: Option<unsafe extern "C" fn()> = None;
 static GOT_SIGHUP: AtomicBool = AtomicBool::new(false);
@@ -66,7 +67,7 @@ impl BackgroundWorker {
         const LEN: usize = 96;
 
         unsafe {
-            CStr::from_ptr(std::mem::transmute::<&[i8; LEN], *const i8>(
+            CStr::from_ptr(std::mem::transmute::<&[c_char; LEN], *const c_char>(
                 &(*pg_sys::MyBgworkerEntry).bgw_name,
             ))
         }
@@ -79,7 +80,7 @@ impl BackgroundWorker {
         const LEN: usize = 128;
 
         unsafe {
-            CStr::from_ptr(std::mem::transmute::<&[i8; LEN], *const i8>(
+            CStr::from_ptr(std::mem::transmute::<&[c_char; LEN], *const c_char>(
                 &(*pg_sys::MyBgworkerEntry).bgw_extra,
             ))
         }
@@ -122,14 +123,14 @@ impl BackgroundWorker {
     /// connect to via SPI
     pub fn connect_worker_to_spi(dbname: Option<&str>, username: Option<&str>) {
         let db = dbname.and_then(|rs| CString::new(rs).ok());
-        let db: *const i8 = db.as_ref().map_or(std::ptr::null(), |i| i.as_ptr());
+        let db: *const c_char = db.as_ref().map_or(std::ptr::null(), |i| i.as_ptr());
 
         let user = username.and_then(|rs| CString::new(rs).ok());
-        let user: *const i8 = user.as_ref().map_or(std::ptr::null(), |i| i.as_ptr());
+        let user: *const c_char = user.as_ref().map_or(std::ptr::null(), |i| i.as_ptr());
 
         unsafe {
             #[cfg(feature = "pg10")]
-            pg_sys::BackgroundWorkerInitializeConnection(db as *mut i8, user as *mut i8);
+            pg_sys::BackgroundWorkerInitializeConnection(db as *mut c_char, user as *mut c_char);
 
             #[cfg(any(feature = "pg11", feature = "pg12", feature = "pg13"))]
             pg_sys::BackgroundWorkerInitializeConnection(db, user, 0);
@@ -440,37 +441,37 @@ type RpgffiChar = RpgffiChar64;
 #[cfg(any(feature = "pg11", feature = "pg12", feature = "pg13"))]
 type RpgffiChar = RpgffiChar96;
 
-struct RpgffiChar64([i8; 64]);
+struct RpgffiChar64([c_char; 64]);
 
 impl<'a> From<&'a str> for RpgffiChar64 {
     fn from(string: &str) -> Self {
         let mut r = [0; 64];
         for (dest, src) in r.iter_mut().zip(string.as_bytes()) {
-            *dest = *src as i8;
+            *dest = *src as c_char;
         }
         RpgffiChar64(r)
     }
 }
 
-struct RpgffiChar96([i8; 96]);
+struct RpgffiChar96([c_char; 96]);
 
 impl<'a> From<&'a str> for RpgffiChar96 {
     fn from(string: &str) -> Self {
         let mut r = [0; 96];
         for (dest, src) in r.iter_mut().zip(string.as_bytes()) {
-            *dest = *src as i8;
+            *dest = *src as c_char;
         }
         RpgffiChar96(r)
     }
 }
 
-struct RpgffiChar128([i8; 128]);
+struct RpgffiChar128([c_char; 128]);
 
 impl<'a> From<&'a str> for RpgffiChar128 {
     fn from(string: &str) -> Self {
         let mut r = [0; 128];
         for (dest, src) in r.iter_mut().zip(string.as_bytes()) {
-            *dest = *src as i8;
+            *dest = *src as c_char;
         }
         RpgffiChar128(r)
     }
