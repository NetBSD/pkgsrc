$NetBSD: patch-src_bootstrap_src_core_sanity.rs,v 1.2 2026/05/07 13:16:15 wiz Exp $

Temporarily add m68k-unknown-netbsd to STAGE0_MISSING_TARGETS.
...while we bootstrap the target, and don't make the presence
while it's a known target a fatal error.

--- src/bootstrap/src/core/sanity.rs.orig	2026-03-02 23:18:25.000000000 +0000
+++ src/bootstrap/src/core/sanity.rs
@@ -49,6 +49,7 @@ const STAGE0_MISSING_TARGETS: &[&str] = 
     "aarch64v8r-unknown-none",
     "aarch64v8r-unknown-none-softfloat",
     "s390x-unknown-none-softfloat",
+    "m68k-unknown-netbsd",
 ];
 
 /// Minimum version threshold for libstdc++ required when using prebuilt LLVM
@@ -277,7 +278,10 @@ than building it.
                 for duplicated_target in duplicated_targets {
                     println!("  {duplicated_target}");
                 }
-                std::process::exit(1);
+// For now don't make this a fatal error.
+// e.g. m68k-unknown-netbsd may be in the list for a while
+// until LLVM is fixed to not emit 16-bit PC-relative relocations only...
+//              std::process::exit(1);
             }
 
             // Check if it's a built-in target.
