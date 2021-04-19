$NetBSD: patch-src_bootstrap_builder.rs,v 1.14 2021/04/19 17:08:09 he Exp $

Do not install 'src'.
Use @PREFIX@, not $ORIGIN in rpath.

Fix RPATH for pkgsrc.

--- src/bootstrap/builder.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -483,7 +483,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
             Kind::Run => describe!(run::ExpandYamlAnchors, run::BuildManifest),
@@ -1082,7 +1081,7 @@ impl<'a> Builder<'a> {
                 rustflags.arg("-Zosx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
