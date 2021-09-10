$NetBSD: patch-compiler_rustc__target_src_spec_solaris__base.rs,v 1.3 2021/09/10 15:09:32 jperkin Exp $

Enable frame pointers on SunOS.

--- compiler/rustc_target/src/spec/solaris_base.rs.orig	2021-07-26 14:43:01.000000000 +0000
+++ compiler/rustc_target/src/spec/solaris_base.rs
@@ -9,6 +9,7 @@ pub fn opts() -> TargetOptions {
         families: vec!["unix".to_string()],
         is_like_solaris: true,
         linker_is_gnu: false,
+        eliminate_frame_pointer: false,
         limit_rdylib_exports: false, // Linker doesn't support this
         eh_frame_header: false,
 
