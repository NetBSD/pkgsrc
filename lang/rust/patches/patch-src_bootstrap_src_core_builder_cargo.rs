$NetBSD: patch-src_bootstrap_src_core_builder_cargo.rs,v 1.3 2025/08/25 17:51:12 wiz Exp $

Find external libunwind and libLLVM in pkgsrc (not just Linux).
Use @PREFIX@ in rpath.

--- src/bootstrap/src/core/builder/cargo.rs.orig	2025-01-27 23:20:59.000000000 +0000
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -251,7 +251,7 @@ impl Cargo {
                 && !target.contains("xous")
             {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/lib"))
             } else {
                 None
             };
@@ -1249,6 +1249,9 @@ impl Builder<'_> {
             // cargo bench/install do not accept `--release` and miri doesn't want it
             !matches!(cmd_kind, Kind::Bench | Kind::Install | Kind::Miri | Kind::MiriSetup | Kind::MiriTest);
 
+        // added for pkgsrc libunwind or external LLVM
+        rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+
         Cargo {
             command: cargo,
             args: vec![],
