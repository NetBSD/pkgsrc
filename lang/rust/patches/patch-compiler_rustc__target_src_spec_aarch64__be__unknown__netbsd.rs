$NetBSD: patch-compiler_rustc__target_src_spec_aarch64__be__unknown__netbsd.rs,v 1.2 2021/09/10 15:09:32 jperkin Exp $

Add aarch64_be NetBSD target.

--- compiler/rustc_target/src/spec/aarch64_be_unknown_netbsd.rs.orig	2021-04-25 17:12:53.986628780 +0200
+++ compiler/rustc_target/src/spec/aarch64_be_unknown_netbsd.rs	2021-04-25 18:00:57.795577197 +0200
@@ -0,0 +1,20 @@
+use crate::abi::Endian;
+use crate::spec::{Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = super::netbsd_base::opts();
+    base.max_atomic_width = Some(128);
+    base.unsupported_abis = super::arm_base::unsupported_abis();
+
+    Target {
+        llvm_target: "aarch64_be-unknown-netbsd".to_string(),
+        pointer_width: 64,
+        data_layout: "E-m:e-i8:8:32-i16:16:32-i64:64-i128:128-n32:64-S128".to_string(),
+        arch: "aarch64".to_string(),
+        options: TargetOptions {
+            mcount: "__mcount".to_string(),
+            endian: Endian::Big,
+            ..base
+        },
+    }
+}
