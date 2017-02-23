$NetBSD: patch-src_librustc__trans_back_linker.rs,v 1.2 2017/02/23 09:35:16 jperkin Exp $

Permit post-install install_name_tool fixup.

--- src/librustc_trans/back/linker.rs.orig	2017-02-09 01:37:48.000000000 +0000
+++ src/librustc_trans/back/linker.rs
@@ -213,6 +213,8 @@ impl<'a> Linker for GnuLinker<'a> {
             // the right `-Wl,-install_name` with an `@rpath` in it.
             if self.sess.opts.cg.rpath ||
                self.sess.opts.debugging_opts.osx_rpath_install_name {
+                // Ensure we can use install_name_tool later to fixup.
+                self.cmd.arg("-Wl,-headerpad_max_install_names");
                 let mut v = OsString::from("-Wl,-install_name,@rpath/");
                 v.push(out_filename.file_name().unwrap());
                 self.cmd.arg(&v);
