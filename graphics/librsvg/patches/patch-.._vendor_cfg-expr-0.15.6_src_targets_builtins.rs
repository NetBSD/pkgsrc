$NetBSD: patch-.._vendor_cfg-expr-0.15.6_src_targets_builtins.rs,v 1.1 2024/04/14 17:25:28 adam Exp $

Add i586-unknown-netbsd.
Needed because of lang/rust/patches/patch-compiler_rustc__target_src_spec_mod.rs
Note that the implementation does a binary search of the target list.
It must be sorted lexically!

--- ../vendor/cfg-expr-0.15.6/src/targets/builtins.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ ../vendor/cfg-expr-0.15.6/src/targets/builtins.rs
@@ -1106,6 +1106,19 @@ pub const ALL_BUILTINS: &[TargetInfo] =
         panic: Panic::unwind,
     },
     TargetInfo {
+        triple: Triple::new_const("i586-unknown-netbsd"),
+        os: Some(Os::netbsd),
+        abi: None,
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
         abi: None,
