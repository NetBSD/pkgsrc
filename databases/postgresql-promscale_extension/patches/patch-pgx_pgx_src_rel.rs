$NetBSD: patch-pgx_pgx_src_rel.rs,v 1.1 2021/08/25 11:06:28 tnn Exp $

Fix build on ARM (signed char assumptions)

--- pgx/pgx/src/rel.rs.orig	2021-04-14 16:14:29.000000000 +0000
+++ pgx/pgx/src/rel.rs
@@ -7,6 +7,7 @@ use crate::{
     PgTupleDesc,
 };
 use std::ops::Deref;
+use std::os::raw::c_char;
 
 pub struct PgRelation {
     boxed: PgBox<pg_sys::RelationData>,
@@ -231,55 +232,55 @@ impl PgRelation {
     pub fn is_table(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_RELATION as i8
+        rd_rel.relkind == pg_sys::RELKIND_RELATION as c_char
     }
 
     pub fn is_matview(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_MATVIEW as i8
+        rd_rel.relkind == pg_sys::RELKIND_MATVIEW as c_char
     }
 
     pub fn is_index(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_INDEX as i8
+        rd_rel.relkind == pg_sys::RELKIND_INDEX as c_char
     }
 
     pub fn is_view(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_VIEW as i8
+        rd_rel.relkind == pg_sys::RELKIND_VIEW as c_char
     }
 
     pub fn is_sequence(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_SEQUENCE as i8
+        rd_rel.relkind == pg_sys::RELKIND_SEQUENCE as c_char
     }
 
     pub fn is_composite_type(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_COMPOSITE_TYPE as i8
+        rd_rel.relkind == pg_sys::RELKIND_COMPOSITE_TYPE as c_char
     }
 
     pub fn is_foreign_table(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_FOREIGN_TABLE as i8
+        rd_rel.relkind == pg_sys::RELKIND_FOREIGN_TABLE as c_char
     }
 
     pub fn is_partitioned_table(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_PARTITIONED_TABLE as i8
+        rd_rel.relkind == pg_sys::RELKIND_PARTITIONED_TABLE as c_char
     }
 
     pub fn is_toast_value(&self) -> bool {
         let rd_rel: &pg_sys::FormData_pg_class =
             unsafe { self.boxed.rd_rel.as_ref().expect("rd_rel is NULL") };
-        rd_rel.relkind == pg_sys::RELKIND_TOASTVALUE as i8
+        rd_rel.relkind == pg_sys::RELKIND_TOASTVALUE as c_char
     }
 
     /// ensures that the returned `PgRelation` is closed by Rust when it is dropped
