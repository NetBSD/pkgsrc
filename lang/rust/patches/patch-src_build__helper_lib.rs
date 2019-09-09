$NetBSD: patch-src_build__helper_lib.rs,v 1.1 2019/09/09 16:19:49 adam Exp $

On Darwin, do not use @rpath for internal libraries.

--- src/build_helper/lib.rs.orig	2019-09-06 11:17:24.000000000 +0000
+++ src/build_helper/lib.rs
@@ -212,7 +212,7 @@ impl NativeLibBoilerplate {
         fs::rename(&src, &dst).unwrap();
         let status = Command::new("install_name_tool")
             .arg("-id")
-            .arg(format!("@rpath/{}", new_name))
+            .arg(format!("@PREFIX@/lib/{}", new_name))
             .arg(&dst)
             .status()
             .expect("failed to execute `install_name_tool`");
