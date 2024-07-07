$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.1 2024/07/07 10:41:21 wiz Exp $

Use @PREFIX@, not $ORIGIN in rpath.
Find external libunwind on Linux.

--- src/bootstrap/src/core/builder.rs.orig	2024-04-18 09:00:07.530512451 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -1687,7 +1687,7 @@ impl<'a> Builder<'a> {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
@@ -2130,6 +2130,11 @@ impl<'a> Builder<'a> {
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
