$NetBSD: patch-src_bootstrap_builder.rs,v 1.29 2024/01/06 19:00:19 he Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2023-10-03 02:52:17.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -1645,7 +1645,7 @@ impl<'a> Builder<'a> {
                 && !target.contains("xous")
             {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
