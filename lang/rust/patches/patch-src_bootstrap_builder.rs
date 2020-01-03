$NetBSD: patch-src_bootstrap_builder.rs,v 1.5 2020/01/03 19:26:33 jperkin Exp $

Do not install 'src'.

--- src/bootstrap/builder.rs.orig	2019-12-16 15:38:05.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -466,7 +466,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
         }
@@ -994,7 +993,7 @@ impl<'a> Builder<'a> {
                       !target.contains("wasm32") &&
                       !target.contains("emscripten") &&
                       !target.contains("fuchsia") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
