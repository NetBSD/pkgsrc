$NetBSD: patch-helix-loader_src_lib.rs,v 1.2 2022/11/11 20:23:39 nikita Exp $

Taken from FreeBSD ports, original patch by ashish@.

--- helix-loader/src/lib.rs.orig	2022-03-30 18:53:07 UTC
+++ helix-loader/src/lib.rs
@@ -41,6 +41,8 @@ pub fn runtime_dir() -> std::path::PathBuf {
         return conf_dir;
     }
 
+    return std::path::PathBuf::from("%%DATADIR%%").join(RT_DIR);
+
     // fallback to location of the executable being run
     std::env::current_exe()
         .ok()
