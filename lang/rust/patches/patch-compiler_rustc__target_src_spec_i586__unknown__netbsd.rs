$NetBSD: patch-compiler_rustc__target_src_spec_i586__unknown__netbsd.rs,v 1.9 2023/10/25 05:50:43 pin Exp $

Add an i586 / pentium variant, in an effort to support AMD Geode etc.

--- compiler/rustc_target/src/spec/i586_unknown_netbsd.rs.orig	2022-12-21 19:11:11.452711494 +0000
+++ compiler/rustc_target/src/spec/i586_unknown_netbsd.rs
@@ -0,0 +1,23 @@
+use crate::spec::{Cc, Lld, LinkerFlavor, StackProbeType, Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = super::netbsd_base::opts();
+    base.cpu = "pentium".into();
+    base.max_atomic_width = Some(64);
+    base.pre_link_args
+        .entry(LinkerFlavor::Gnu(Cc::Yes, Lld::No))
+        .or_default()
+        .push("-m32".into());
+    // don't use probe-stack=inline-asm until rust-lang/rust#83139 is resolved.
+    base.stack_probes = StackProbeType::Call;
+
+    Target {
+        llvm_target: "i586-unknown-netbsdelf".into(),
+        pointer_width: 32,
+        data_layout: "e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-\
+            f64:32:64-f80:32-n8:16:32-S128"
+            .into(),
+        arch: "x86".into(),
+        options: TargetOptions { mcount: "__mcount".into(), ..base },
+    }
+}
