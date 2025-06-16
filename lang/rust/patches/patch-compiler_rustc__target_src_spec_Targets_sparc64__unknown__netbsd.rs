$NetBSD: patch-compiler_rustc__target_src_spec_Targets_sparc64__unknown__netbsd.rs,v 1.1 2025/06/16 21:10:43 he Exp $

--- compiler/rustc_target/src/spec/targets/sparc64_unknown_netbsd.rs.orig	2025-03-31 21:37:24.000000000 +0000
+++ compiler/rustc_target/src/spec/targets/sparc64_unknown_netbsd.rs
@@ -1,12 +1,14 @@
 use rustc_abi::Endian;
 
-use crate::spec::{Cc, LinkerFlavor, Lld, Target, TargetOptions, base};
+use crate::spec::{Cc, LinkerFlavor, Lld, Target, base};
 
 pub(crate) fn target() -> Target {
     let mut base = base::netbsd::opts();
     base.cpu = "v9".into();
     base.add_pre_link_args(LinkerFlavor::Gnu(Cc::Yes, Lld::No), &["-m64"]);
     base.max_atomic_width = Some(64);
+    base.endian = Endian::Big;
+    base.mcount = "__mcount".into();
 
     Target {
         llvm_target: "sparc64-unknown-netbsd".into(),
@@ -19,6 +21,6 @@ pub(crate) fn target() -> Target {
         pointer_width: 64,
         data_layout: "E-m:e-i64:64-i128:128-n32:64-S128".into(),
         arch: "sparc64".into(),
-        options: TargetOptions { endian: Endian::Big, mcount: "__mcount".into(), ..base },
+        options: base,
     }
 }
