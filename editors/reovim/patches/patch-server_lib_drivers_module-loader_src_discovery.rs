$NetBSD: patch-server_lib_drivers_module-loader_src_discovery.rs,v 1.1 2026/04/09 17:16:54 pin Exp $

Allow compilation on *BSD.

--- server/lib/drivers/module-loader/src/discovery.rs.orig	2026-04-09 12:34:36.950570004 +0000
+++ server/lib/drivers/module-loader/src/discovery.rs
@@ -65,17 +65,18 @@ pub const fn library_extension() -> &'static str {
 #[must_use]
 pub const fn library_extension() -> &'static str {
     #[cfg(target_os = "linux")]
-    {
-        "so"
-    }
+    { "so" }
     #[cfg(target_os = "macos")]
-    {
-        "dylib"
-    }
+    { "dylib" }
     #[cfg(target_os = "windows")]
-    {
-        "dll"
-    }
+    { "dll" }
+    #[cfg(any(
+        target_os = "netbsd",
+        target_os = "freebsd",
+        target_os = "openbsd",
+        target_os = "dragonfly",
+    ))]
+    { "so" }
 }
 
 /// Get library filename for a module name.
