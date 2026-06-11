$NetBSD: patch-src_bootstrap_src_core_sanity.rs,v 1.3 2026/06/11 07:00:57 wiz Exp $

Add m68k-unknown-netbsd to "missing stage0" list.

--- src/bootstrap/src/core/sanity.rs.orig	2026-05-25 23:21:07.000000000 +0000
+++ src/bootstrap/src/core/sanity.rs
@@ -39,6 +39,7 @@ const STAGE0_MISSING_TARGETS: &[&str] = 
     // just a dummy comment so the list doesn't get onelined
     "x86_64-unknown-linux-gnumsan",
     "x86_64-unknown-linux-gnutsan",
+    "m68k-unknown-netbsd",
 ];
 
 /// Minimum version threshold for libstdc++ required when using prebuilt LLVM
@@ -267,7 +268,10 @@ than building it.
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
