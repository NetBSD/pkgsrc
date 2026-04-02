$NetBSD: patch-compiler_rustc__target_src_spec_targets_m68k__unknown__netbsd.rs,v 1.1 2026/04/02 19:06:34 wiz Exp $

Add a target description for NetBSD/m68k.

--- /dev/null	2026-02-24 21:43:45.067063051 +0000
+++ compiler/rustc_target/src/spec/targets/m68k_unknown_netbsd.rs	2026-02-24 21:48:57.106967890 +0000
@@ -0,0 +1,31 @@
+use rustc_abi::Endian;
+
+use crate::spec::{Arch, LinkSelfContainedDefault, Target, TargetMetadata, TargetOptions, base};
+
+pub(crate) fn target() -> Target {
+    let mut base = base::netbsd::opts();
+    base.cpu = "M68020".into();
+    base.max_atomic_width = Some(32);
+
+    Target {
+        llvm_target: "m68k-unknown-netbsd".into(),
+        metadata: TargetMetadata {
+            description: Some("Motorola 680x0 NetBSD".into()),
+            tier: Some(3),
+            host_tools: Some(false),
+            std: Some(true),
+        },
+        pointer_width: 32,
+        data_layout: "E-m:e-p:32:16:32-i8:8:8-i16:16:16-i32:16:32-n8:16:32-a:0:16-S16".into(),
+        arch: Arch::M68k,
+        options: TargetOptions {
+            endian: Endian::Big,
+            mcount: "_mcount".into(),
+
+            // LLD currently does not have support for M68k
+            link_self_contained: LinkSelfContainedDefault::False,
+            ..base
+        },
+    }
+}
+
