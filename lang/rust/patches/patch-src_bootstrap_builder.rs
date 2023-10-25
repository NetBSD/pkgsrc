$NetBSD: patch-src_bootstrap_builder.rs,v 1.27 2023/10/25 05:50:43 pin Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2023-08-23 19:50:10.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -1612,7 +1612,7 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") && !target.contains("aix") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
