$NetBSD: patch-src_librustc__target_spec_solaris__base.rs,v 1.3 2020/03/13 18:34:53 jperkin Exp $

Enable frame pointers on SunOS.

--- src/librustc_target/spec/solaris_base.rs.orig	2020-03-09 22:11:17.000000000 +0000
+++ src/librustc_target/spec/solaris_base.rs
@@ -8,6 +8,7 @@ pub fn opts() -> TargetOptions {
         has_rpath: true,
         target_family: Some("unix".to_string()),
         is_like_solaris: true,
+        eliminate_frame_pointer: false,
         limit_rdylib_exports: false, // Linker doesn't support this
 
         ..Default::default()
