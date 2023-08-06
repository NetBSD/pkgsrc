$NetBSD: patch-src_util_reload.rs,v 1.1 2023/08/06 05:25:06 pin Exp $

Allow building on NetBSD.

--- src/util/reload.rs.orig	2023-08-05 16:41:58.000000000 +0000
+++ src/util/reload.rs
@@ -2,7 +2,7 @@ use super::{arguments::Cli, config::Conf
 use color_eyre::{eyre::Result, Report};
 use std::process::Command;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 pub fn reload_apps_linux(args: &Cli, config: &ConfigFile) -> Result<(), Report> {
     reload_app("kitty", "SIGUSR1")?;
     reload_app("waybar", "SIGUSR2")?;
