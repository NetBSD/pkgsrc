$NetBSD: patch-compiler_rustc__codegen__ssa_src_back_linker.rs,v 1.4 2022/01/21 23:20:36 he Exp $

Do not use @rpath on Darwin.

--- compiler/rustc_codegen_ssa/src/back/linker.rs.orig	2021-09-06 18:42:35.000000000 +0000
+++ compiler/rustc_codegen_ssa/src/back/linker.rs
@@ -305,7 +305,7 @@ impl<'a> GccLinker<'a> {
             // the right `-Wl,-install_name` with an `@rpath` in it.
             if self.sess.opts.cg.rpath || self.sess.opts.debugging_opts.osx_rpath_install_name {
                 self.linker_arg("-install_name");
-                let mut v = OsString::from("@rpath/");
+                let mut v = OsString::from("@PREFIX@/lib/");
                 v.push(out_filename.file_name().unwrap());
                 self.linker_arg(&v);
             }
