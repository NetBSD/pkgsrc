$NetBSD: patch-compiler_rustc__target_src_spec_aarch64__be__unknown__netbsd.rs,v 1.5 2023/01/23 18:49:04 he Exp $

Add aarch64_be NetBSD target.

--- compiler/rustc_target/src/spec/aarch64_be_unknown_netbsd.rs.orig	2021-09-10 09:47:35.334562996 +0000
+++ compiler/rustc_target/src/spec/aarch64_be_unknown_netbsd.rs
@@ -0,0 +1,17 @@
+use crate::abi::Endian;
+use crate::spec::{Target, TargetOptions};
+
+pub fn target() -> Target {
+    Target {
+        llvm_target: "aarch64_be-unknown-netbsd".into(),
+        pointer_width: 64,
+        data_layout: "E-m:e-i8:8:32-i16:16:32-i64:64-i128:128-n32:64-S128".into(),
+        arch: "aarch64".into(),
+        options: TargetOptions {
+            mcount: "__mcount".into(),
+            max_atomic_width: Some(128),
+            endian: Endian::Big,
+            ..super::netbsd_base::opts()
+        },
+    }
+}
