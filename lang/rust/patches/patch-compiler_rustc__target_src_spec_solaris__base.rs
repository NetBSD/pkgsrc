$NetBSD: patch-compiler_rustc__target_src_spec_solaris__base.rs,v 1.2 2021/02/14 08:24:30 he Exp $

Enable frame pointers on SunOS.

--- compiler/rustc_target/src/spec/solaris_base.rs.orig	2020-12-29 03:03:08.000000000 +0000
+++ compiler/rustc_target/src/spec/solaris_base.rs
@@ -9,6 +9,7 @@ pub fn opts() -> TargetOptions {
         has_rpath: true,
         os_family: Some("unix".to_string()),
         is_like_solaris: true,
+        eliminate_frame_pointer: false,
         limit_rdylib_exports: false, // Linker doesn't support this
         eh_frame_header: false,
 
