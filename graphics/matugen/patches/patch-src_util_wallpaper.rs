$NetBSD: patch-src_util_wallpaper.rs,v 1.1 2023/08/06 05:25:06 pin Exp $

Allow building on NetBSD.

--- src/util/wallpaper.rs.orig	2023-08-05 16:41:58.000000000 +0000
+++ src/util/wallpaper.rs
@@ -8,7 +8,7 @@ use super::{
     reload::reload_app,
 };
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 pub fn set_wallaper(config: &ConfigFile, args: &Cli) -> Result<(), Report> {
     let wallpaper_tool = match &config.config.wallpaper_tool {
         Some(wallpaper_tool) => wallpaper_tool,
@@ -32,7 +32,7 @@ pub fn set_wallaper(config: &ConfigFile,
     }
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 fn set_wallaper_swaybg(path: &String) -> Result<(), Report> {
     reload_app("swaybg", "SIGUSR1")?;
 
@@ -45,7 +45,7 @@ fn set_wallaper_swaybg(path: &String) ->
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 fn set_wallaper_swwww(config: &ConfigFile, path: &String) -> Result<(), Report> {
     let mut binding = Command::new("swww");
     let cmd = binding.stdout(Stdio::null()).stderr(Stdio::null());
@@ -62,7 +62,7 @@ fn set_wallaper_swwww(config: &ConfigFil
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 fn set_wallaper_nitrogen(path: &String) -> Result<(), Report> {
     let mut binding = Command::new("nitrogen");
     let cmd = binding.stdout(Stdio::null()).stderr(Stdio::null());
@@ -72,7 +72,7 @@ fn set_wallaper_nitrogen(path: &String) 
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 fn set_wallaper_feh(config: &ConfigFile, path: &String) -> Result<(), Report> {
     let mut binding = Command::new("feh");
     let cmd = binding.stdout(Stdio::null()).stderr(Stdio::null());
