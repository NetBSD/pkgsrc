$NetBSD: patch-src_bootstrap_builder.rs,v 1.24 2022/11/15 23:11:14 he Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2022-06-27 13:37:07.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -1702,7 +1701,7 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
