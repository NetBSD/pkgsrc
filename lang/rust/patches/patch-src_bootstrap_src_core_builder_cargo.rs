$NetBSD: patch-src_bootstrap_src_core_builder_cargo.rs,v 1.4 2026/05/07 13:16:15 wiz Exp $

Find external libunwind and libLLVM in pkgsrc (not just Linux).
Use @PREFIX@ in rpath.

--- src/bootstrap/src/core/builder/cargo.rs.orig	2026-04-14 19:55:32.000000000 +0000
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -299,7 +299,7 @@ impl Cargo {
                 && !target.contains("xous")
             {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/lib"))
             } else {
                 None
             };
@@ -1422,6 +1422,9 @@ impl Builder<'_> {
                 }
             };
 
+        // added for pkgsrc libunwind or external LLVM
+        rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+
         Cargo {
             command: cargo,
             args: vec![],
