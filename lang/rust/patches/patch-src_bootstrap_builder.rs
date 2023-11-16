$NetBSD: patch-src_bootstrap_builder.rs,v 1.28 2023/11/16 09:49:12 he Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2023-08-23 19:50:10.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -1637,7 +1637,7 @@ impl<'a> Builder<'a> {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.contains("windows") && !target.contains("aix") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
