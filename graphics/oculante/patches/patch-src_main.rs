$NetBSD: patch-src_main.rs,v 1.2 2022/08/24 05:20:19 pin Exp $

Allow lazy_loop on NetBSD to reduce CPU load

--- src/main.rs.orig	2022-08-21 09:16:54.000000000 +0000
+++ src/main.rs
@@ -60,6 +60,11 @@ fn main() -> Result<(), String> {
         window_config = window_config.lazy_loop();
     }
 
+    #[cfg(target_os = "netbsd")]
+    {
+        window_config = window_config.lazy_loop().vsync();
+    }
+
     #[cfg(target_os = "macos")]
     {
         window_config = window_config.lazy_loop().vsync();
