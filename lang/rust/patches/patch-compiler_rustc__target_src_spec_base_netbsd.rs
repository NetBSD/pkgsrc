$NetBSD: patch-compiler_rustc__target_src_spec_base_netbsd.rs,v 1.7 2026/04/02 19:06:34 wiz Exp $

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- compiler/rustc_target/src/spec/base/netbsd.rs.orig	2024-01-06 19:57:14.887897867 +0000
+++ compiler/rustc_target/src/spec/base/netbsd.rs
@@ -1,12 +1,23 @@
-use crate::spec::{Os, RelroLevel, TargetOptions, cvs};
+use crate::spec::{Cc, Lld, LinkerFlavor, Os, RelroLevel, TargetOptions, cvs};
 
 pub(crate) fn opts() -> TargetOptions {
+    let add_linker_paths =
+        &[
+            // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-R@PREFIX@/lib/libatomic",
+            "-Wl,-L@PREFIX@/lib/libatomic",
+        ];
+    let pre_link_args = TargetOptions::link_args(
+        LinkerFlavor::Gnu(Cc::Yes, Lld::No),
+        add_linker_paths
+    );
     TargetOptions {
         os: Os::NetBsd,
         dynamic_linking: true,
         families: cvs!["unix"],
         no_default_libraries: false,
         has_rpath: true,
+        pre_link_args,
         position_independent_executables: true,
         relro_level: RelroLevel::Full,
         has_thread_local: true,
