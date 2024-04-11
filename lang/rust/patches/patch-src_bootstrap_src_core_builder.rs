$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.2 2024/04/11 19:53:50 tnn Exp $

Use @PREFIX@, not $ORIGIN in rpath.
Find external libunwind on Linux.

--- src/bootstrap/src/core/builder.rs.orig	2023-12-21 16:55:28.000000000 +0000
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
@@ -2095,6 +2095,11 @@ impl<'a> Builder<'a> {
             rustflags.arg("-Zinline-mir");
         }
 
+        // added for pkgsrc libunwind
+        if target.contains("linux") {
+            rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+        }
+
         // set rustc args passed from command line
         let rustc_args =
             self.config.cmd.rustc_args().iter().map(|s| s.to_string()).collect::<Vec<_>>();
