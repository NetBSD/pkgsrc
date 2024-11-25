$NetBSD: patch-compiler_rustc__codegen__ssa_src_back_linker.rs,v 1.19 2024/11/25 14:37:35 tnn Exp $

Do not use @rpath on Darwin.
Find external libunwind on Linux.

--- compiler/rustc_codegen_ssa/src/back/linker.rs.orig	2024-09-04 15:07:06.000000000 +0000
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
@@ -528,6 +528,10 @@ impl<'a> Linker for GccLinker<'a> {
     }
 
     fn link_dylib_by_name(&mut self, name: &str, verbatim: bool, as_needed: bool) {
+        if self.sess.target.os.contains("linux") && name == "unwind" {
+            self.link_arg("-rpath,@PREFIX@/lib");
+            self.link_arg("-L@PREFIX@/lib");
+        }
         if self.sess.target.os == "illumos" && name == "c" {
             // libc will be added via late_link_args on illumos so that it will
             // appear last in the library search order.
