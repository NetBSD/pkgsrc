$NetBSD: patch-src_bootstrap_bin_rustc.rs,v 1.1 2017/09/30 04:42:43 ryoon Exp $

* Set RPATH for pkgsrc wrapper

--- src/bootstrap/bin/rustc.rs.orig	2017-08-27 18:26:05.000000000 +0000
+++ src/bootstrap/bin/rustc.rs
@@ -225,7 +225,7 @@ fn main() {
                 cmd.arg("-Z").arg("osx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
