$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.1 2024/03/03 14:53:32 he Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/src/core/builder.rs.orig	2024-01-13 20:06:50.748741545 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -1678,7 +1678,7 @@ impl<'a> Builder<'a> {
                 && !target.contains("xous")
             {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
