$NetBSD: patch-src_bootstrap_bin_rustc.rs,v 1.2 2018/01/08 09:33:58 ryoon Exp $

* Set RPATH for pkgsrc wrapper

--- src/bootstrap/bin/rustc.rs.orig	2018-01-01 21:50:13.000000000 +0000
+++ src/bootstrap/bin/rustc.rs
@@ -224,7 +224,7 @@ fn main() {
                 cmd.arg("-Z").arg("osx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
