$NetBSD: patch-compiler_rustc__target_src_spec_x86__64__sun__solaris.rs,v 1.1 2021/01/01 20:44:48 he Exp $

Enable stack probes on SunOS.

--- compiler/rustc_target/src/spec/x86_64_sun_solaris.rs.orig	2019-01-16 09:30:27.000000000 +0000
+++ compiler/rustc_target/src/spec/x86_64_sun_solaris.rs
@@ -15,7 +15,7 @@ pub fn target() -> TargetResult {
     base.pre_link_args.insert(LinkerFlavor::Gcc, vec!["-m64".to_string()]);
     base.cpu = "x86-64".to_string();
     base.max_atomic_width = Some(64);
-    base.stack_probes = true;
+    base.stack_probes = false;
 
     Ok(Target {
         llvm_target: "x86_64-pc-solaris".to_string(),
