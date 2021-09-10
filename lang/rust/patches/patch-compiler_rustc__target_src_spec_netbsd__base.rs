$NetBSD: patch-compiler_rustc__target_src_spec_netbsd__base.rs,v 1.4 2021/09/10 15:09:32 jperkin Exp $

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- compiler/rustc_target/src/spec/netbsd_base.rs.orig	2021-07-26 14:43:01.000000000 +0000
+++ compiler/rustc_target/src/spec/netbsd_base.rs
@@ -1,6 +1,14 @@
-use crate::spec::{RelroLevel, TargetOptions};
+use crate::spec::{LinkArgs, LinkerFlavor, RelroLevel, TargetOptions};
 
 pub fn opts() -> TargetOptions {
+    let mut args = LinkArgs::new();
+    args.insert (
+        LinkerFlavor::Gcc,
+        vec![
+            // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-L@PREFIX@/lib/libatomic".to_string(),
+        ],
+    );
     TargetOptions {
         os: "netbsd".to_string(),
         dynamic_linking: true,
@@ -8,6 +16,7 @@ pub fn opts() -> TargetOptions {
         families: vec!["unix".to_string()],
         no_default_libraries: false,
         has_rpath: true,
+        pre_link_args: args,
         position_independent_executables: true,
         relro_level: RelroLevel::Full,
         use_ctors_section: true,
