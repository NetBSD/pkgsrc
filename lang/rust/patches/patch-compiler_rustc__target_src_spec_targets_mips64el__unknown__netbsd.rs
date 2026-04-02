$NetBSD: patch-compiler_rustc__target_src_spec_targets_mips64el__unknown__netbsd.rs,v 1.8 2026/04/02 19:06:34 wiz Exp $

Provide a mips64el target with N32, suitable for NetBSD/mips64el.

--- compiler/rustc_target/src/spec/targets/mips64el_unknown_netbsd.rs.orig	2024-01-13 14:16:30.122042614 +0000
+++ compiler/rustc_target/src/spec/targets/mips64el_unknown_netbsd.rs
@@ -0,0 +1,32 @@
+//! A target tuple for NetBSD/mips64
+
+use rustc_abi::Endian;
+
+use crate::spec::{Abi, Arch, Target, TargetMetadata, TargetOptions, base};
+
+pub(crate) fn target() -> Target {
+    let mut base = base::netbsd::opts();
+    base.max_atomic_width = Some(32);
+    base.cpu = "mips32".into();
+
+    Target {
+        llvm_target: "mipsel-unknown-netbsd".into(),
+        metadata: TargetMetadata {
+            description: Some("NetBSD/mips64 with n32 ABI".into()),
+            tier: Some(3),
+            host_tools: Some(false),
+            std: Some(false),
+        },
+        pointer_width: 32,
+        data_layout: "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64".into(),
+        arch: Arch::Mips64,
+        options: TargetOptions {
+            abi: Abi::ElfV2,
+            endian: Endian::Little,
+            features: "+soft-float,+abi=n32".into(),
+            llvm_abiname: "n32".into(),
+            mcount: "__mcount".into(),
+            ..base
+        },
+    }
+}
