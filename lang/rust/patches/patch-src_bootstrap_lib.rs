$NetBSD: patch-src_bootstrap_lib.rs,v 1.1.2.1 2018/01/28 18:24:02 bsiegert Exp $

Don't filter out optimization flags.

--- src/bootstrap/lib.rs.orig	2018-01-01 21:50:13.000000000 +0000
+++ src/bootstrap/lib.rs
@@ -636,7 +636,6 @@ impl Build {
         // cc-rs because the build scripts will determine that for themselves.
         let mut base = self.cc[&target].args().iter()
                            .map(|s| s.to_string_lossy().into_owned())
-                           .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
                            .collect::<Vec<_>>();
 
         // If we're compiling on macOS then we add a few unconditional flags
