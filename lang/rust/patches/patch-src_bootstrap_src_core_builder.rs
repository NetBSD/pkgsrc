$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.6 2025/02/02 13:34:47 he Exp $

Find external libunwind on Linux.
Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/src/core/builder.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -2211,6 +2211,11 @@ impl<'a> Builder<'a> {
             rustdocflags.arg("--cfg=parallel_compiler");
         }
 
+	// added for pkgsrc libunwind
+	if target.contains("linux") {
+		rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+	}
+
         Cargo {
             command: cargo,
             compiler,
@@ -2557,7 +2562,7 @@ impl Cargo {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };
