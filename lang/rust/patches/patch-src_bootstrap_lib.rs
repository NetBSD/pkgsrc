$NetBSD: patch-src_bootstrap_lib.rs,v 1.1 2017/12/07 12:12:44 maya Exp $

Don't filter out optimization flags.

--- src/bootstrap/lib.rs.orig	2017-11-22 21:33:00.000000000 +0000
+++ src/bootstrap/lib.rs
@@ -622,7 +622,6 @@ impl Build {
         // cc-rs because the build scripts will determine that for themselves.
         let mut base = self.cc[&target].0.args().iter()
                            .map(|s| s.to_string_lossy().into_owned())
-                           .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
                            .collect::<Vec<_>>();
 
         // If we're compiling on macOS then we add a few unconditional flags
