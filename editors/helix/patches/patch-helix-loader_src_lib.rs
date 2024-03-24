$NetBSD: patch-helix-loader_src_lib.rs,v 1.4 2024/03/24 20:06:49 adam Exp $

Taken from FreeBSD ports, original patch by ashish@.

--- helix-loader/src/lib.rs.orig	2023-10-25 16:37:27.000000000 +0000
+++ helix-loader/src/lib.rs
@@ -75,8 +75,6 @@ fn prioritize_runtime_dirs() -> Vec<Path
         rt_dirs.push(path);
     }
 
-    let conf_rt_dir = config_dir().join(RT_DIR);
-    rt_dirs.push(conf_rt_dir);
 
     if let Ok(dir) = std::env::var("HELIX_RUNTIME") {
         rt_dirs.push(dir.into());
@@ -90,14 +88,8 @@ fn prioritize_runtime_dirs() -> Vec<Path
         rt_dirs.push(dir.into());
     }
 
-    // fallback to location of the executable being run
-    // canonicalize the path in case the executable is symlinked
-    let exe_rt_dir = std::env::current_exe()
-        .ok()
-        .and_then(|path| std::fs::canonicalize(path).ok())
-        .and_then(|path| path.parent().map(|path| path.to_path_buf().join(RT_DIR)))
-        .unwrap();
-    rt_dirs.push(exe_rt_dir);
+    rt_dirs.push(PathBuf::from("@DATADIR@").join(RT_DIR));
+
     rt_dirs
 }
 
