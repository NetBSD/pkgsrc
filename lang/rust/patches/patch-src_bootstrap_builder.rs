$NetBSD: patch-src_bootstrap_builder.rs,v 1.10 2020/06/08 11:19:33 he Exp $

Do not install 'src'.
Use @PREFIX@, not $ORIGIN in rpath.

Fix RPATH for pkgsrc.

--- src/bootstrap/builder.rs.orig	2020-01-27 15:34:02.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -465,7 +465,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
         }
@@ -970,7 +969,7 @@ impl<'a> Builder<'a> {
                 rustflags.arg("-Zosx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
