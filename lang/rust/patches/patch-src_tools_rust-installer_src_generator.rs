$NetBSD: patch-src_tools_rust-installer_src_generator.rs,v 1.1 2018/11/27 15:45:23 adam Exp $

Do not create tarballs; not needed for PkgSrc installation.

--- src/tools/rust-installer/src/generator.rs.orig	2018-11-26 21:41:04.000000000 +0000
+++ src/tools/rust-installer/src/generator.rs
@@ -13,7 +13,6 @@ use std::path::Path;
 
 use errors::*;
 use super::Scripter;
-use super::Tarballer;
 use util::*;
 
 actor!{
@@ -97,11 +96,6 @@ impl Generator {
         // Make the tarballs
         create_dir_all(&self.output_dir)?;
         let output = Path::new(&self.output_dir).join(&self.package_name);
-        let mut tarballer = Tarballer::default();
-        tarballer.work_dir(self.work_dir)
-            .input(self.package_name)
-            .output(path_to_str(&output)?);
-        tarballer.run()?;
 
         Ok(())
     }
