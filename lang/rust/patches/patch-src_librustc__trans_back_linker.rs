$NetBSD: patch-src_librustc__trans_back_linker.rs,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Permit post-install install_name_tool fixup.

--- src/librustc_trans/back/linker.rs.orig	2016-08-16 01:54:35.000000000 +0000
+++ src/librustc_trans/back/linker.rs
@@ -206,6 +206,8 @@ impl<'a> Linker for GnuLinker<'a> {
             self.cmd.args(&["-dynamiclib", "-Wl,-dylib"]);
 
             if self.sess.opts.cg.rpath {
+                // Ensure we can use install_name_tool later to fixup.
+                self.cmd.arg("-Wl,-headerpad_max_install_names");
                 let mut v = OsString::from("-Wl,-install_name,@rpath/");
                 v.push(out_filename.file_name().unwrap());
                 self.cmd.arg(&v);
