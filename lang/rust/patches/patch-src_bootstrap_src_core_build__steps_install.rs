$NetBSD: patch-src_bootstrap_src_core_build__steps_install.rs,v 1.5 2026/04/02 19:06:34 wiz Exp $

Drop "docs" from installation (takes forever), add "rust".

--- src/bootstrap/src/core/build_steps/install.rs.orig	2025-10-28 16:34:16.000000000 +0000
+++ src/bootstrap/src/core/build_steps/install.rs
@@ -206,7 +206,7 @@ macro_rules! install {
 install!((self, builder, _config),
     Docs, path = "src/doc", _config.docs, IS_HOST: false, {
         let tarball = builder.ensure(dist::Docs { host: self.target }).expect("missing docs");
-        install_sh(builder, "docs", self.build_compiler, Some(self.target), &tarball);
+        install_sh(builder, "rust", self.build_compiler, Some(self.target), &tarball);
     };
     Std, path = "library/std", true, IS_HOST: false, {
         // `expect` should be safe, only None when host != build, but this
