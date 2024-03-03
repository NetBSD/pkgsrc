$NetBSD: patch-compiler_rustc__target_src_spec_targets_mips64el__unknown__netbsd.rs,v 1.1 2024/03/03 14:53:32 he Exp $

Provide a mips64el target with N32, suitable for NetBSD/mips64el.

--- compiler/rustc_target/src/spec/targets/mips64el_unknown_netbsd.rs.orig	2024-01-13 14:16:30.122042614 +0000
+++ compiler/rustc_target/src/spec/targets/mips64el_unknown_netbsd.rs
@@ -0,0 +1,22 @@
+use crate::abi::Endian;
+use crate::spec::{base, Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = base::netbsd::opts();
+    base.max_atomic_width = Some(32);
+    base.cpu = "mips32".into();
+
+    Target {
+        llvm_target: "mipsel-unknown-netbsd".into(),
+        pointer_width: 32,
+        data_layout: "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64".into(),
+        arch: "mips".into(),
+        options: TargetOptions {
+            abi: "n32".into(),
+            features: "+soft-float,+abi=n32".into(),
+            endian: Endian::Little,
+            mcount: "__mcount".into(),
+            ..base
+        },
+    }
+}
