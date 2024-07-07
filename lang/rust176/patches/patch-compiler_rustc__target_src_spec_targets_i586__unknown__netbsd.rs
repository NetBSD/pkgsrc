$NetBSD: patch-compiler_rustc__target_src_spec_targets_i586__unknown__netbsd.rs,v 1.1 2024/07/07 10:41:21 wiz Exp $

Change to Inline stack probing, as suggested by
https://github.com/rust-lang/rust/pull/120411

--- compiler/rustc_target/src/spec/targets/i586_unknown_netbsd.rs.orig	2024-02-26 11:56:11.087253310 +0000
+++ compiler/rustc_target/src/spec/targets/i586_unknown_netbsd.rs
@@ -4,7 +4,7 @@ pub fn target() -> Target {
     let mut base = base::netbsd::opts();
     base.cpu = "pentium".into();
     base.max_atomic_width = Some(64);
-    base.stack_probes = StackProbeType::Call;
+    base.stack_probes = StackProbeType::Inline;
 
     Target {
         llvm_target: "i586-unknown-netbsdelf".into(),
