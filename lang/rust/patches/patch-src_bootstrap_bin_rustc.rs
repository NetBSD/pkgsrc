$NetBSD: patch-src_bootstrap_bin_rustc.rs,v 1.4 2018/09/14 10:04:43 jperkin Exp $

* Set RPATH for pkgsrc wrapper

--- src/bootstrap/bin/rustc.rs.orig	2018-09-11 03:37:38.000000000 +0000
+++ src/bootstrap/bin/rustc.rs
@@ -233,7 +233,7 @@ fn main() {
                 cmd.arg("-Z").arg("osx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") && !target.contains("wasm32") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
