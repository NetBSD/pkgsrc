$NetBSD: patch-src_parse.rs,v 1.1 2023/01/18 10:56:42 pin Exp $

Add support for NetBSD.

--- src/parse.rs.orig	2022-12-20 06:00:41.000000000 +0000
+++ src/parse.rs
@@ -139,7 +139,7 @@ fn fn_name_from_lang(lang: &str) -> Stri
 fn lib_name_from_lang(lang: &str) -> String {
     let extension = if cfg!(target_os = "macos") {
         "dylib"
-    } else if cfg!(target_os = "linux") {
+    } else if cfg!(any(target_os = "linux", target_os = "netbsd")) {
         "so"
     } else if cfg!(target_os = "windows") {
         "dll"
