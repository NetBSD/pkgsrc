$NetBSD: patch-src_bootstrap_bin_rustc.rs,v 1.3 2018/05/18 12:45:52 ryoon Exp $

* Set RPATH for pkgsrc wrapper

--- src/bootstrap/bin/rustc.rs.orig	2018-05-07 17:31:28.000000000 +0000
+++ src/bootstrap/bin/rustc.rs
@@ -226,7 +226,7 @@ fn main() {
                 cmd.arg("-Z").arg("osx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") && !target.contains("wasm32") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
