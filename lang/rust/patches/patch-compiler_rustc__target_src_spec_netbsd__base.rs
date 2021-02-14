$NetBSD: patch-compiler_rustc__target_src_spec_netbsd__base.rs,v 1.3 2021/02/14 08:24:30 he Exp $

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- compiler/rustc_target/src/spec/netbsd_base.rs.orig	2020-08-24 15:00:49.000000000 +0000
+++ compiler/rustc_target/src/spec/netbsd_base.rs
@@ -10,6 +10,8 @@ pub fn opts() -> TargetOptions {
             // libraries which follow this flag.  Thus, use it before
             // specifying libraries to link to.
             "-Wl,--as-needed".to_string(),
+            // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-L@PREFIX@/lib/libatomic".to_string(),
         ],
     );
 
