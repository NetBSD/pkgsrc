$NetBSD: patch-compiler_rustc__target_src_spec_netbsd__base.rs,v 1.6 2022/08/30 19:22:17 he Exp $

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- compiler/rustc_target/src/spec/netbsd_base.rs.orig	2022-05-18 01:29:36.000000000 +0000
+++ compiler/rustc_target/src/spec/netbsd_base.rs
@@ -1,6 +1,14 @@
-use crate::spec::{cvs, RelroLevel, TargetOptions};
+use crate::spec::{cvs, RelroLevel, LinkArgs, LinkerFlavor, TargetOptions};
 
 pub fn opts() -> TargetOptions {
+    let mut args = LinkArgs::new();
+    args.insert (
+        LinkerFlavor::Gcc,
+        vec![
+            // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-L@PREFIX@/lib/libatomic".into(),
+        ],
+    );
     TargetOptions {
         os: "netbsd".into(),
         dynamic_linking: true,
@@ -8,6 +16,7 @@ pub fn opts() -> TargetOptions {
         families: cvs!["unix"],
         no_default_libraries: false,
         has_rpath: true,
+        pre_link_args: args,
         position_independent_executables: true,
         relro_level: RelroLevel::Full,
         use_ctors_section: true,
