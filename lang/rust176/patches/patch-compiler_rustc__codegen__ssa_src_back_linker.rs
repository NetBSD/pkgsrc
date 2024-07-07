$NetBSD: patch-compiler_rustc__codegen__ssa_src_back_linker.rs,v 1.1 2024/07/07 10:41:20 wiz Exp $

Do not use @rpath on Darwin.
Find external libunwind on Linux.

--- compiler/rustc_codegen_ssa/src/back/linker.rs.orig	2024-04-18 08:34:17.044783799 +0000
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
@@ -462,6 +462,10 @@ impl<'a> Linker for GccLinker<'a> {
                 self.linker_arg("--as-needed");
             }
         }
+        if self.sess.target.os.contains("linux") && lib == "unwind" {
+            self.linker_arg("-rpath,@PREFIX@/lib");
+            self.linker_arg("-L@PREFIX@/lib");
+        }
     }
     fn link_staticlib(&mut self, lib: &str, verbatim: bool) {
         self.hint_static();
