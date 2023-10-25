$NetBSD: patch-vendor_rustc-ap-rustc__target_src_spec_aarch64__be__unknown__netbsd.rs,v 1.8 2023/10/25 05:50:43 pin Exp $

Add aarch64_be NetBSD target.

--- /dev/null	2021-04-26 00:02:43.147970692 +0200
+++ vendor/rustc-ap-rustc_target/src/spec/aarch64_be_unknown_netbsd.rs	2021-04-26 00:07:44.657579025 +0200
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
