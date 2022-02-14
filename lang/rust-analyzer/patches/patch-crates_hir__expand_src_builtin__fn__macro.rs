$NetBSD: patch-crates_hir__expand_src_builtin__fn__macro.rs,v 1.1 2022/02/14 08:27:17 adam Exp $

Use pre-1.58.0 format strings.

--- crates/hir_expand/src/builtin_fn_macro.rs.orig	2022-02-14 08:20:47.000000000 +0000
+++ crates/hir_expand/src/builtin_fn_macro.rs
@@ -452,11 +452,11 @@ fn relative_file(
     let call_site = call_id.as_file().original_file(db);
     let path = AnchoredPath { anchor: call_site, path: path_str };
     let res = db.resolve_path(path).ok_or_else(|| {
-        mbe::ExpandError::Other(format!("failed to load file `{path_str}`").into())
+        mbe::ExpandError::Other(format!("failed to load file `{}`", path_str).into())
     })?;
     // Prevent include itself
     if res == call_site && !allow_recursion {
-        Err(mbe::ExpandError::Other(format!("recursive inclusion of `{path_str}`").into()))
+        Err(mbe::ExpandError::Other(format!("recursive inclusion of `{}`", path_str).into()))
     } else {
         Ok(res)
     }
