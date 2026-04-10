$NetBSD: patch-server_lib_drivers_module-loader_src_discovery.rs,v 1.2 2026/04/10 18:29:41 pin Exp $

Allow building on other *nix.

--- ../reovim-0.14.4/server/lib/drivers/module-loader/src/discovery.rs.orig	2026-04-10 18:15:39.711016518 +0000
+++ ../reovim-0.14.4/server/lib/drivers/module-loader/src/discovery.rs
@@ -64,7 +64,14 @@ pub const fn library_extension() -> &'static str {
 /// Get shared library extension for the current platform.
 #[must_use]
 pub const fn library_extension() -> &'static str {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(
+        target_os = "linux",
+        target_os = "netbsd",
+        target_os = "freebsd",
+        target_os = "openbsd",
+        target_os = "dragonfly",
+        target_os = "solaris",
+    ))]
     {
         "so"
     }
