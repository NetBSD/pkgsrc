$NetBSD: patch-src_bootstrap_builder.rs,v 1.2 2019/03/03 09:16:21 he Exp $

Do not install 'src'.

--- src/bootstrap/builder.rs.orig	2018-11-25 15:56:35.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -464,7 +464,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
         }
