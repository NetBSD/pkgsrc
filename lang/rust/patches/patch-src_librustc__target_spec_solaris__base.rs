$NetBSD: patch-src_librustc__target_spec_solaris__base.rs,v 1.1 2019/05/31 14:11:23 jperkin Exp $

Enable frame pointers on SunOS.

--- src/librustc_target/spec/solaris_base.rs.orig	2019-01-16 09:30:27.000000000 +0000
+++ src/librustc_target/spec/solaris_base.rs
@@ -18,6 +18,7 @@ pub fn opts() -> TargetOptions {
         has_rpath: true,
         target_family: Some("unix".to_string()),
         is_like_solaris: true,
+        eliminate_frame_pointer: false,
 
         .. Default::default()
     }
