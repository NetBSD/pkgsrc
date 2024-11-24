$NetBSD: patch-compiler_rustc__codegen__ssa_src_back_linker.rs,v 1.18 2024/11/24 16:13:43 he Exp $

Do not use @rpath on Darwin.
Find external libunwind on Linux.

--- compiler/rustc_codegen_ssa/src/back/linker.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ compiler/rustc_codegen_ssa/src/back/linker.rs
@@ -402,7 +402,7 @@ impl<'a> GccLinker<'a> {
             // principled solution at some point to force the compiler to pass
             // the right `-Wl,-install_name` with an `@rpath` in it.
             if self.sess.opts.cg.rpath || self.sess.opts.unstable_opts.osx_rpath_install_name {
-                let mut rpath = OsString::from("@rpath/");
+                let mut rpath = OsString::from("@PREFIX@/lib/");
                 rpath.push(out_filename.file_name().unwrap());
                 self.link_arg("-install_name").link_arg(rpath);
             }
@@ -880,6 +880,10 @@ impl<'a> Linker for MsvcLinker<'a> {
 
     fn link_dylib_by_name(&mut self, name: &str, verbatim: bool, _as_needed: bool) {
         self.link_arg(format!("{}{}", name, if verbatim { "" } else { ".lib" }));
+        if self.sess.target.os.contains("linux") && name == "unwind" {
+            self.link_arg("-rpath,@PREFIX@/lib");
+            self.link_arg("-L@PREFIX@/lib");
+        }
     }
 
     fn link_dylib_by_path(&mut self, path: &Path, _as_needed: bool) {
