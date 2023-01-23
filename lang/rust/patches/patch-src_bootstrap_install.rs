$NetBSD: patch-src_bootstrap_install.rs,v 1.1 2023/01/23 18:49:04 he Exp $

Backport https://github.com/rust-lang/rust/commit/bcb75e61

--- src/bootstrap/install.rs.orig	2022-12-12 16:02:12.000000000 +0000
+++ src/bootstrap/install.rs
@@ -200,10 +200,14 @@ install!((self, builder, _config),
         install_sh(builder, "clippy", self.compiler.stage, Some(self.target), &tarball);
     };
     Miri, alias = "miri", Self::should_build(_config), only_hosts: true, {
-        let tarball = builder
-            .ensure(dist::Miri { compiler: self.compiler, target: self.target })
-            .expect("missing miri");
-        install_sh(builder, "miri", self.compiler.stage, Some(self.target), &tarball);
+        if let Some(tarball) = builder.ensure(dist::Miri { compiler: self.compiler, target: self.target }) {
+            install_sh(builder, "miri", self.compiler.stage, Some(self.target), &tarball);
+        } else {
+            // Miri is only available on nightly
+            builder.info(
+                &format!("skipping Install miri stage{} ({})", self.compiler.stage, self.target),
+            );
+        }
     };
     Rustfmt, alias = "rustfmt", Self::should_build(_config), only_hosts: true, {
         if let Some(tarball) = builder.ensure(dist::Rustfmt {
