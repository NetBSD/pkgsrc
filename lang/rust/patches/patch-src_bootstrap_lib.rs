$NetBSD: patch-src_bootstrap_lib.rs,v 1.19 2023/01/23 18:49:04 he Exp $

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name

--- src/bootstrap/lib.rs.orig	2021-09-06 18:42:35.000000000 +0000
+++ src/bootstrap/lib.rs
@@ -954,14 +954,13 @@ impl Build {
             .args()
             .iter()
             .map(|s| s.to_string_lossy().into_owned())
-            .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
             .collect::<Vec<String>>();
 
         // If we're compiling on macOS then we add a few unconditional flags
         // indicating that we want libc++ (more filled out than libstdc++) and
         // we want to compile for 10.7. This way we can ensure that
         // LLVM/etc are all properly compiled.
-        if target.contains("apple-darwin") {
+        if target.contains("apple-darwin") || target.contains("freebsd") {
             base.push("-stdlib=libc++".into());
         }
 
