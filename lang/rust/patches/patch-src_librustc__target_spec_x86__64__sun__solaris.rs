$NetBSD: patch-src_librustc__target_spec_x86__64__sun__solaris.rs,v 1.1 2019/05/31 14:11:23 jperkin Exp $

Enable stack probes on SunOS.

--- src/librustc_target/spec/x86_64_sun_solaris.rs.orig	2019-01-16 09:30:27.000000000 +0000
+++ src/librustc_target/spec/x86_64_sun_solaris.rs
@@ -15,7 +15,7 @@ pub fn target() -> TargetResult {
     base.pre_link_args.insert(LinkerFlavor::Gcc, vec!["-m64".to_string()]);
     base.cpu = "x86-64".to_string();
     base.max_atomic_width = Some(64);
-    base.stack_probes = true;
+    base.stack_probes = false;
 
     Ok(Target {
         llvm_target: "x86_64-pc-solaris".to_string(),
