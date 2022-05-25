$NetBSD: patch-src_bootstrap_builder.rs,v 1.21 2022/05/25 21:31:26 he Exp $

Do not install 'src'.
Use @PREFIX@, not $ORIGIN in rpath.

Fix RPATH for pkgsrc.

--- src/bootstrap/builder.rs.orig	2021-09-06 18:42:35.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -617,7 +617,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
             Kind::Run => describe!(run::ExpandYamlAnchors, run::BuildManifest, run::BumpStage0),
@@ -1277,7 +1276,7 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
