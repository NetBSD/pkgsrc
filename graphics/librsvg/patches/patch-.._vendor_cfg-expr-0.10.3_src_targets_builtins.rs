$NetBSD: patch-.._vendor_cfg-expr-0.10.3_src_targets_builtins.rs,v 1.1 2022/06/18 01:56:22 gutteridge Exp $

Add i586-unknown-netbsd.
Needed because of lang/rust/patches/patch-compiler_rustc__target_src_spec_mod.rs
Note that the implementation does a binary search of the target list.
It must be sorted lexically!

--- ../vendor/cfg-expr-0.10.3/src/targets/builtins.rs.orig	1973-11-29 16:33:09.000000000 -0500
+++ ../vendor/cfg-expr-0.10.3/src/targets/builtins.rs
@@ -806,6 +806,18 @@
         panic: Panic::unwind,
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
+        has_atomics: HasAtomics::atomic_8_16_32_64_ptr,
+        panic: Panic::unwind,
+    },
+    TargetInfo {
         triple: Triple::new_const("i686-apple-darwin"),
         os: Some(Os::macos),
         arch: Arch::x86,
