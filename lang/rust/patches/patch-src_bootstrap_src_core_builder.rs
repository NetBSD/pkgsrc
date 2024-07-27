$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.5 2024/07/27 02:35:24 tnn Exp $

Find external libunwind on Linux.
Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/src/core/builder.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -2149,6 +2149,11 @@ impl<'a> Builder<'a> {
             rustflags.arg(v);
         });
 
+        // added for pkgsrc libunwind
+        if target.contains("linux") {
+            rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+        }
+
         Cargo {
             command: cargo,
             compiler,
@@ -2513,7 +2518,7 @@ impl Cargo {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
