$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.4 2024/07/15 03:32:23 wiz Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/src/core/builder.rs.orig	2024-07-07 12:16:58.347642901 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -2513,7 +2518,7 @@ impl Cargo {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
