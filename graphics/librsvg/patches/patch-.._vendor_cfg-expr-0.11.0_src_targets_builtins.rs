$NetBSD: patch-.._vendor_cfg-expr-0.11.0_src_targets_builtins.rs,v 1.1 2023/04/11 05:45:45 adam Exp $

Add i586-unknown-netbsd.
Needed because of lang/rust/patches/patch-compiler_rustc__target_src_spec_mod.rs
Note that the implementation does a binary search of the target list.
It must be sorted lexically!

--- ../vendor/cfg-expr-0.11.0/src/targets/builtins.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/cfg-expr-0.11.0/src/targets/builtins.rs
@@ -854,6 +854,18 @@ pub const ALL_BUILTINS: &[TargetInfo] = 
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
