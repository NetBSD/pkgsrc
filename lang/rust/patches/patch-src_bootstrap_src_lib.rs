$NetBSD: patch-src_bootstrap_src_lib.rs,v 1.10 2026/01/14 06:44:31 wiz Exp $

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name.
Don't assume files in ${PREFIX}/lib are readable by the building user.

--- src/bootstrap/src/lib.rs.orig	2025-09-14 15:05:11.000000000 +0000
+++ src/bootstrap/src/lib.rs
@@ -1256,7 +1256,6 @@ impl Build {
         base.args()
             .iter()
             .map(|s| s.to_string_lossy().into_owned())
-            .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
             .collect::<Vec<String>>()
     }
 
@@ -1272,7 +1271,8 @@ impl Build {
         // If we're compiling C++ on macOS then we add a flag indicating that
         // we want libc++ (more filled out than libstdc++), ensuring that
         // LLVM/etc are all properly compiled.
-        if matches!(c, CLang::Cxx) && target.contains("apple-darwin") {
+        if matches!(c, CLang::Cxx) &&
+            (target.contains("apple-darwin") || target.contains("freebsd")) {
             base.push("-stdlib=libc++".into());
         }
 
@@ -1813,7 +1813,12 @@ impl Build {
             // but if that fails just fall back to a slow `copy` operation.
         } else {
             if let Err(e) = fs::copy(&src, dst) {
-                panic!("failed to copy `{}` to `{}`: {}", src.display(), dst.display(), e)
+                if e.kind() == io::ErrorKind::PermissionDenied {
+                    eprintln!("Skipping copy of `{}` to `{}`: {}", src.display(), dst.display(), e);
+                    return;
+                } else {
+                    panic!("failed to copy `{}` to `{}`: {}", src.display(), dst.display(), e)
+                }
             }
             t!(fs::set_permissions(dst, metadata.permissions()));
 
