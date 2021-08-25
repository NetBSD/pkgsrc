$NetBSD: patch-pgx_pgx_src_enum__helper.rs,v 1.1 2021/08/25 11:06:28 tnn Exp $

Fix build on ARM (signed char assumptions)

--- pgx/pgx/src/enum_helper.rs.orig	2021-04-14 16:14:29.000000000 +0000
+++ pgx/pgx/src/enum_helper.rs
@@ -5,6 +5,7 @@
 
 use crate::pg_sys::pgx_GETSTRUCT;
 use crate::{ereport, pg_sys, PgLogLevel, PgSqlErrorCode};
+use std::os::raw::c_char;
 
 pub fn lookup_enum_by_oid(enumval: pg_sys::Oid) -> (String, pg_sys::Oid, f32) {
     let tup = unsafe {
@@ -30,7 +31,7 @@ pub fn lookup_enum_by_oid(enumval: pg_sy
     let en = unsafe { pgx_GETSTRUCT(tup) } as pg_sys::Form_pg_enum;
     let en = unsafe { en.as_ref() }.unwrap();
     let result = (
-        unsafe { std::ffi::CStr::from_ptr(en.enumlabel.data.as_ptr() as *const i8) }
+        unsafe { std::ffi::CStr::from_ptr(en.enumlabel.data.as_ptr() as *const c_char) }
             .to_str()
             .unwrap()
             .to_string(),
