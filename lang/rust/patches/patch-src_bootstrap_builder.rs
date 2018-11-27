$NetBSD: patch-src_bootstrap_builder.rs,v 1.1 2018/11/27 15:45:23 adam Exp $

Do not install 'src'.

--- src/bootstrap/builder.rs.orig	2018-11-25 15:56:35.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -473,7 +473,6 @@ impl<'a> Builder<'a> {
                 install::Rustfmt,
                 install::Clippy,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
         }
