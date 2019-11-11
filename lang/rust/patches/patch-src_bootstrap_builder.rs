$NetBSD: patch-src_bootstrap_builder.rs,v 1.3 2019/11/11 09:09:11 he Exp $

Do not install 'src'.

--- src/bootstrap/builder.rs.orig	2019-09-23 21:15:52.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -468,7 +468,6 @@ impl<'a> Builder<'a> {
                 install::Clippy,
                 install::Miri,
                 install::Analysis,
-                install::Src,
                 install::Rustc
             ),
         }
