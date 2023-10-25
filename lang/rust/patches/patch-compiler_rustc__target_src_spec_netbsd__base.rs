$NetBSD: patch-compiler_rustc__target_src_spec_netbsd__base.rs,v 1.9 2023/10/25 05:50:43 pin Exp $

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- compiler/rustc_target/src/spec/netbsd_base.rs.orig	2022-12-12 16:02:12.000000000 +0000
+++ compiler/rustc_target/src/spec/netbsd_base.rs
@@ -1,12 +1,20 @@
-use crate::spec::{cvs, RelroLevel, TargetOptions};
+use crate::spec::{cvs, Cc, Lld, RelroLevel, LinkerFlavor, TargetOptions};
 
 pub fn opts() -> TargetOptions {
+    let pre_link_args = TargetOptions::link_args(
+        LinkerFlavor::Gnu(Cc::Yes, Lld::No),
+       &[
+            // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-L@PREFIX@/lib/libatomic".into(),
+        ],
+    );
     TargetOptions {
         os: "netbsd".into(),
         dynamic_linking: true,
         families: cvs!["unix"],
         no_default_libraries: false,
         has_rpath: true,
+        pre_link_args,
         position_independent_executables: true,
         relro_level: RelroLevel::Full,
         use_ctors_section: true,
