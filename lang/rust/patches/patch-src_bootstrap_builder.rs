$NetBSD: patch-src_bootstrap_builder.rs,v 1.4 2019/11/12 12:06:04 ryoon Exp $

Do not install 'src'.

--- src/bootstrap/builder.rs.orig	2019-11-04 15:45:21.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -465,7 +465,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
         }
@@ -971,7 +970,7 @@ impl<'a> Builder<'a> {
             } else if !target.contains("windows") &&
                       !target.contains("wasm32") &&
                       !target.contains("fuchsia") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
