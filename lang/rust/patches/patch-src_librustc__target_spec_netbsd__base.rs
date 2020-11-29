$NetBSD: patch-src_librustc__target_spec_netbsd__base.rs,v 1.1 2020/11/29 20:15:15 he Exp $

For the benefit of powerpc, when libatomic-links is installed,
search the directory containing the symlinks to -latomic.

--- src/librustc_target/spec/netbsd_base.rs.orig	2020-08-24 15:00:49.000000000 +0000
+++ src/librustc_target/spec/netbsd_base.rs
@@ -10,6 +10,8 @@ pub fn opts() -> TargetOptions {
             // libraries which follow this flag.  Thus, use it before
             // specifying libraries to link to.
             "-Wl,--as-needed".to_string(),
+	    // For the benefit of powerpc, when libatomic-links is installed,
+            "-Wl,-L/usr/pkg/lib/libatomic".to_string(),
         ],
     );
 
