$NetBSD: patch-src_bootstrap_lib.rs,v 1.8 2021/04/19 17:08:09 he Exp $

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name

--- src/bootstrap/lib.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ src/bootstrap/lib.rs
@@ -836,7 +836,6 @@ impl Build {
             .args()
             .iter()
             .map(|s| s.to_string_lossy().into_owned())
-            .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
             .collect::<Vec<String>>();
 
         // If we're compiling on macOS then we add a few unconditional flags
@@ -847,6 +846,11 @@ impl Build {
             base.push("-stdlib=libc++".into());
         }
 
+        // FreeBSD (from 10.2) also uses libc++.
+        if target.contains("freebsd") {
+            base.push("-stdlib=libc++".into());
+        }
+
         // Work around an apparently bad MinGW / GCC optimization,
         // See: http://lists.llvm.org/pipermail/cfe-dev/2016-December/051980.html
         // See: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=78936
