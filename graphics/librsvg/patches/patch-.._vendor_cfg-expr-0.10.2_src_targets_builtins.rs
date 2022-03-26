$NetBSD: patch-.._vendor_cfg-expr-0.10.2_src_targets_builtins.rs,v 1.1 2022/03/26 15:24:29 tnn Exp $

Add i586-unknown-netbsd.
Needed because of lang/rust/patches/patch-compiler_rustc__target_src_spec_mod.rs
Note that the implementation does a binary search of the target list.
It must be sorted lexically!

--- ../vendor/cfg-expr-0.10.2/src/targets/builtins.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/cfg-expr-0.10.2/src/targets/builtins.rs
@@ -654,6 +654,16 @@ pub const ALL_BUILTINS: &[TargetInfo] = 
         endian: Endian::little,
     },
     TargetInfo {
+        triple: Triple::new_const("i586-unknown-netbsd"),
+        os: Some(Os::netbsd),
+        arch: Arch::x86,
+        env: None,
+        vendor: Some(Vendor::unknown),
+        families: Families::unix,
+        pointer_width: 32,
+        endian: Endian::little,
+    },
+    TargetInfo {
         triple: Triple::new_const("i686-apple-darwin"),
         os: Some(Os::macos),
         arch: Arch::x86,
