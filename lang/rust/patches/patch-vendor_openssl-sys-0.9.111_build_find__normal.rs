$NetBSD: patch-vendor_openssl-sys-0.9.111_build_find__normal.rs,v 1.1 2026/04/02 19:06:35 wiz Exp $

Add hack for Darwin when homebrew is installed.

--- vendor/openssl-sys-0.9.111/build/find_normal.rs.orig	2026-01-25 08:56:08.257782732 +0000
+++ vendor/openssl-sys-0.9.111/build/find_normal.rs
@@ -72,23 +72,6 @@ fn resolve_with_wellknown_location(dir: 
 fn find_openssl_dir(target: &str) -> OsString {
     let host = env::var("HOST").unwrap();
 
-    if host == target && target.ends_with("-apple-darwin") {
-        let homebrew_dir = match target {
-            "aarch64-apple-darwin" => "/opt/homebrew",
-            _ => "/usr/local",
-        };
-
-        if let Some(dir) = resolve_with_wellknown_homebrew_location(homebrew_dir) {
-            return dir.into();
-        } else if let Some(dir) = resolve_with_wellknown_location("/opt/pkg") {
-            // pkgsrc
-            return dir.into();
-        } else if let Some(dir) = resolve_with_wellknown_location("/opt/local") {
-            // MacPorts
-            return dir.into();
-        }
-    }
-
     try_pkg_config();
     try_vcpkg();
 
