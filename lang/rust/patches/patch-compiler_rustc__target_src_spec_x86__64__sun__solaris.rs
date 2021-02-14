$NetBSD: patch-compiler_rustc__target_src_spec_x86__64__sun__solaris.rs,v 1.2 2021/02/14 08:24:31 he Exp $

Disable stack probes on SunOS.

--- compiler/rustc_target/src/spec/x86_64_sun_solaris.rs.orig	2020-12-29 03:03:08.000000000 +0000
+++ compiler/rustc_target/src/spec/x86_64_sun_solaris.rs
@@ -5,7 +5,6 @@ pub fn target() -> Target {
     base.pre_link_args.insert(LinkerFlavor::Gcc, vec!["-m64".to_string()]);
     base.cpu = "x86-64".to_string();
     base.max_atomic_width = Some(64);
-    base.stack_probes = true;
 
     Target {
         llvm_target: "x86_64-pc-solaris".to_string(),
