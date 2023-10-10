$NetBSD: patch-compiler_rustc__target_src_spec_riscv64gc__unknown__netbsd.rs,v 1.2 2023/10/10 13:12:33 pin Exp $

Target spec for NetBSD/riscv64.

--- compiler/rustc_target/src/spec/riscv64gc_unknown_netbsd.rs.orig	2023-07-02 04:17:02.369254026 +0000
+++ compiler/rustc_target/src/spec/riscv64gc_unknown_netbsd.rs	2023-07-02 18:24:04.339160957 +0000
@@ -0,0 +1,19 @@
+use crate::spec::{CodeModel, Target, TargetOptions};
+
+pub fn target() -> Target {
+    Target {
+        llvm_target: "riscv64-unknown-netbsd".into(),
+        pointer_width: 64,
+        data_layout: "e-m:e-p:64:64-i64:64-i128:128-n32:64-S128".into(),
+        arch: "riscv64".into(),
+        options: TargetOptions {
+            code_model: Some(CodeModel::Medium),
+            cpu: "generic-rv64".into(),
+            features: "+m,+a,+f,+d,+c".into(),
+            llvm_abiname: "lp64d".into(),
+            max_atomic_width: Some(64),
+            mcount: "__mcount".into(),
+            ..super::netbsd_base::opts()
+        },
+    }
+}
