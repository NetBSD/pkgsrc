$NetBSD: patch-compiler_rustc__target_src_spec_solaris__base.rs,v 1.1 2021/01/01 20:44:48 he Exp $

Enable frame pointers on SunOS.

--- compiler/rustc_target/src/spec/solaris_base.rs.orig	2020-08-24 15:00:49.000000000 +0000
+++ compiler/rustc_target/src/spec/solaris_base.rs
@@ -7,6 +7,7 @@ pub fn opts() -> TargetOptions {
         has_rpath: true,
         target_family: Some("unix".to_string()),
         is_like_solaris: true,
+	eliminate_frame_pointer: false,
         limit_rdylib_exports: false, // Linker doesn't support this
         eh_frame_header: false,
 
