$NetBSD: patch-src_bootstrap_src_core_builder.rs,v 1.7 2025/02/23 08:53:54 he Exp $

Find external libunwind and libLLVM on pkgsrc (not just Linux).
Use @PREFIX@ in rpath.

Also, follow up on
https://github.com/rust-lang/rust/issues/133629 by applying
https://github.com/rust-lang/rust/pull/136309
which should fix the cross-compile failure.

--- src/bootstrap/src/core/builder.rs.orig	2024-11-26 10:12:09.000000000 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -1701,7 +1701,10 @@ impl<'a> Builder<'a> {
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
@@ -1709,6 +1712,7 @@ impl<'a> Builder<'a> {
                         .arg("-")
                         .run_capture(self)
                         .stderr();
+
                     let not_supported = error
                         .lines()
                         .any(|line| line.contains("unsupported crate type `proc-macro`"));
@@ -2262,6 +2266,9 @@ impl<'a> Builder<'a> {
             rustdocflags.arg("--cfg=parallel_compiler");
         }
 
+        // added for pkgsrc libunwind and LLVM
+        rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
+
         Cargo {
             command: cargo,
             compiler,
@@ -2617,7 +2624,7 @@ impl Cargo {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/lib"))
             } else {
                 None
             };
