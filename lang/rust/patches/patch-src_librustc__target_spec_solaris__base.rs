$NetBSD: patch-src_librustc__target_spec_solaris__base.rs,v 1.2 2019/08/29 14:09:57 he Exp $

Enable frame pointers on SunOS.

--- src/librustc_target/spec/solaris_base.rs.orig	2019-08-13 06:27:22.000000000 +0000
+++ src/librustc_target/spec/solaris_base.rs
@@ -8,6 +8,7 @@ pub fn opts() -> TargetOptions {
         has_rpath: true,
         target_family: Some("unix".to_string()),
         is_like_solaris: true,
+        eliminate_frame_pointer: false,
         limit_rdylib_exports: false, // Linker doesn't support this
 
         .. Default::default()
