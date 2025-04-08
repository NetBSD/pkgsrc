$NetBSD: patch-src_bootstrap_src_core_builder_cargo.rs,v 1.1 2025/04/08 09:31:07 wiz Exp $

Find external libunwind and libLLVM in pkgsrc (not just Linux).
Use @PREFIX@ in rpath.

Adapt fix to
https://github.com/rust-lang/rust/issues/133629
(files restructured upstream)

--- src/bootstrap/src/core/builder/cargo.rs.orig	2025-01-27 23:20:59.000000000 +0000
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -238,7 +238,7 @@ impl Cargo {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/lib"))
             } else {
                 None
             };
@@ -648,7 +648,10 @@ impl Builder<'_> {
                 // Build proc macros both for the host and the target unless proc-macros are not
                 // supported by the target.
                 if target != compiler.host && cmd_kind != Kind::Check {
-                    let error = command(self.rustc(compiler))
+                    let mut rustc_cmd = command(self.rustc(compiler));
+                    self.add_rustc_lib_path(compiler, &mut rustc_cmd);
+
+                    let error = rustc_cmd
                         .arg("--target")
                         .arg(target.rustc_target_arg())
                         .arg("--print=file-names")
@@ -1212,6 +1215,9 @@ impl Builder<'_> {
             }
         }
 
+	// added for pkgsrc libunwind or external LLVM
+	rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+
         Cargo {
             command: cargo,
             compiler,
