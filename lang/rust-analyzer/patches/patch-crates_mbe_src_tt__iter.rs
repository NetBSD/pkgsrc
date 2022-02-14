$NetBSD: patch-crates_mbe_src_tt__iter.rs,v 1.1 2022/02/14 08:27:17 adam Exp $

Use pre-1.58.0 format strings.

--- crates/mbe/src/tt_iter.rs.orig	2022-02-14 08:19:00.000000000 +0000
+++ crates/mbe/src/tt_iter.rs
@@ -106,7 +106,7 @@ impl<'a> TtIter<'a> {
         }
 
         let err = if error || !cursor.is_root() {
-            Some(ExpandError::BindingError(format!("expected {entry_point:?}").into()))
+            Some(ExpandError::BindingError(format!("expected {:?}", entry_point).into()))
         } else {
             None
         };
