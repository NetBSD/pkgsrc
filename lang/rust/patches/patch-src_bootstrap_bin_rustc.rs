$NetBSD: patch-src_bootstrap_bin_rustc.rs,v 1.5 2019/01/19 12:44:08 ryoon Exp $

* Set RPATH for pkgsrc wrapper

--- src/bootstrap/bin/rustc.rs.orig	2019-01-16 09:30:27.000000000 +0000
+++ src/bootstrap/bin/rustc.rs
@@ -237,7 +237,7 @@ fn main() {
             } else if !target.contains("windows") &&
                       !target.contains("wasm32") &&
                       !target.contains("fuchsia") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,@PREFIX@/lib")
             } else {
                 None
             };
