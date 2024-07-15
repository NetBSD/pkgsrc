$NetBSD: patch-compiler_rustc__codegen__ssa_src_back_linker.rs,v 1.16 2024/07/15 03:32:23 wiz Exp $

Do not use @rpath on Darwin.

--- compiler/rustc_codegen_ssa/src/back/linker.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ compiler/rustc_codegen_ssa/src/back/linker.rs
@@ -312,7 +312,7 @@ impl<'a> GccLinker<'a> {
             // principled solution at some point to force the compiler to pass
             // the right `-Wl,-install_name` with an `@rpath` in it.
             if self.sess.opts.cg.rpath || self.sess.opts.unstable_opts.osx_rpath_install_name {
-                let mut rpath = OsString::from("@rpath/");
+                let mut rpath = OsString::from("@PREFIX@/lib/");
                 rpath.push(out_filename.file_name().unwrap());
                 self.linker_args(&[OsString::from("-install_name"), rpath]);
             }
