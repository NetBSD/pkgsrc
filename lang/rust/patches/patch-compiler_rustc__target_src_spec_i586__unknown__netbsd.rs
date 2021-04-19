$NetBSD: patch-compiler_rustc__target_src_spec_i586__unknown__netbsd.rs,v 1.1 2021/04/19 17:08:09 he Exp $

Add an i586 / pentium variant, in an effort to support AMD Geode etc.

--- compiler/rustc_target/src/speci586_unknown_netbsd.rs.orig	2021-04-11 00:12:43.084770395 +0200
+++ compiler/rustc_target/src/spec/i586_unknown_netbsd.rs	2021-04-17 00:25:10.240902011 +0200
@@ -0,0 +1,19 @@
+use crate::spec::{LinkerFlavor, Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = super::netbsd_base::opts();
+    base.cpu = "pentium".to_string();
+    base.max_atomic_width = Some(64);
+    base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m32".to_string());
+    base.stack_probes = true;
+
+    Target {
+        llvm_target: "i586-unknown-netbsdelf".to_string(),
+        pointer_width: 32,
+        data_layout: "e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-\
+            f64:32:64-f80:32-n8:16:32-S128"
+            .to_string(),
+        arch: "x86".to_string(),
+        options: TargetOptions { mcount: "__mcount".to_string(), ..base },
+    }
+}
