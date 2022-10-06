$NetBSD: patch-src_main.rs,v 1.1 2022/10/06 07:43:28 pin Exp $

Allow building on NetBSD

--- src/main.rs.orig	2022-10-04 22:21:07.000000000 +0000
+++ src/main.rs
@@ -5,7 +5,7 @@ mod generators;
 mod tips;
 
 mod capture;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 mod linux;
 #[cfg(target_os = "macos")]
 mod macos;
@@ -13,7 +13,7 @@ mod utils;
 #[cfg(target_os = "windows")]
 mod win;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "netbsd"))]
 use crate::linux::*;
 #[cfg(target_os = "macos")]
 use crate::macos::*;
