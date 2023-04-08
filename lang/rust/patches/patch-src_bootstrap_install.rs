$NetBSD: patch-src_bootstrap_install.rs,v 1.2 2023/04/08 18:18:11 he Exp $

Apply fix from https://github.com/rust-lang/rust/pull/109256.

--- src/bootstrap/install.rs.orig	2023-03-21 21:31:48.458992230 +0000
+++ src/bootstrap/install.rs
@@ -210,10 +210,13 @@ install!((self, builder, _config),
         }
     };
     LlvmTools, alias = "llvm-tools", Self::should_build(_config), only_hosts: true, {
-        let tarball = builder
-            .ensure(dist::LlvmTools { target: self.target })
-            .expect("missing llvm-tools");
-        install_sh(builder, "llvm-tools", self.compiler.stage, Some(self.target), &tarball);
+        if let Some(tarball) = builder.ensure(dist::LlvmTools { target: self.target }) {
+            install_sh(builder, "llvm-tools", self.compiler.stage, Some(self.target), &tarball);
+        } else {
+            builder.info(
+                &format!("skipping llvm-tools stage{} ({}): external LLVM", self.compiler.stage, self.target),
+            );
+        }
     };
     Rustfmt, alias = "rustfmt", Self::should_build(_config), only_hosts: true, {
         if let Some(tarball) = builder.ensure(dist::Rustfmt {
