$NetBSD: patch-src_config_mod.rs,v 1.1 2026/04/23 18:16:55 pin Exp $

Allow building on NetBSD.

--- src/config/mod.rs.orig	2026-04-22 07:26:41.313147253 +0000
+++ src/config/mod.rs
@@ -344,7 +344,7 @@ impl Default for Config {
             #[cfg(target_os = "macos")]
             enclosure_command: "open {url}".into(),
 
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "linux", target_os = "netbsd"))] 
             enclosure_command: "xdg-open {url}".into(),
 
             video_enclosure_command: None,
