$NetBSD: patch-src_bootstrap_src_lib.rs,v 1.1 2024/03/03 14:53:32 he Exp $

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name

--- src/bootstrap/src/lib.rs.orig	2024-01-06 20:52:50.892941220 +0000
+++ src/bootstrap/src/lib.rs
@@ -1195,13 +1195,13 @@ impl Build {
             .args()
             .iter()
             .map(|s| s.to_string_lossy().into_owned())
-            .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
             .collect::<Vec<String>>();
 
         // If we're compiling C++ on macOS then we add a flag indicating that
         // we want libc++ (more filled out than libstdc++), ensuring that
         // LLVM/etc are all properly compiled.
-        if matches!(c, CLang::Cxx) && target.contains("apple-darwin") {
+        if matches!(c, CLang::Cxx) && 
+            (target.contains("apple-darwin") || target.contains("freebsd")) {
             base.push("-stdlib=libc++".into());
         }
 
