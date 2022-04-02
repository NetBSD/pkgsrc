$NetBSD: patch-helix-loader_src_lib.rs,v 1.1 2022/04/02 09:36:15 nikita Exp $

Taken from FreeBSD ports, original patch by ashish@.

--- helix-loader/src/lib.rs.orig	2022-03-30 18:53:07 UTC
+++ helix-loader/src/lib.rs
@@ -21,6 +21,8 @@ pub fn runtime_dir() -> std::path::PathBuf {
         return std::path::PathBuf::from(dir).parent().unwrap().join(RT_DIR);
     }
 
+    return std::path::PathBuf::from("%%DATADIR%%").join(RT_DIR);
+
     // fallback to location of the executable being run
     std::env::current_exe()
         .ok()
