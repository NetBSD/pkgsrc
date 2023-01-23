$NetBSD: patch-src_bootstrap_builder.rs,v 1.25 2023/01/23 18:49:04 he Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2022-12-12 16:02:12.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -1710,7 +1710,7 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
