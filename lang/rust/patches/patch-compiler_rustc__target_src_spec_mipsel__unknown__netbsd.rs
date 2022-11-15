$NetBSD: patch-compiler_rustc__target_src_spec_mipsel__unknown__netbsd.rs,v 1.1 2022/11/15 23:11:14 he Exp $

Add target spec for NetBSD/mipsel.

--- compiler/rustc_target/src/spec/mipsel_unknown_netbsd.rs.orig	2022-11-06 18:16:59.750850353 +0000
+++ compiler/rustc_target/src/spec/mipsel_unknown_netbsd.rs	2022-11-06 18:14:10.846209169 +0000
@@ -0,0 +1,19 @@
+use crate::abi::Endian;
+use crate::spec::{Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = super::netbsd_base::opts();
+    base.max_atomic_width = Some(32);
+
+    Target {
+	llvm_target: "mipsel-unknown-netbsd".into(),
+	pointer_width: 32,
+	data_layout: "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64".into(),
+	arch: "mips".into(),
+	options: TargetOptions {
+	    mcount: "__mcount".into(),
+	    endian: Endian::Little,
+	    ..base
+	},
+    }
+}
