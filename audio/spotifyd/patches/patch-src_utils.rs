$NetBSD: patch-src_utils.rs,v 1.2 2025/04/13 15:28:08 pin Exp $

Allow building on NetBSD.

--- src/utils.rs.orig	2025-04-13 15:09:04.578021815 +0000
+++ src/utils.rs
@@ -4,6 +4,7 @@ use std::{env, time::Duration};
 #[cfg(any(
     target_os = "freebsd",
     target_os = "linux",
+    target_os = "netbsd",
     target_os = "openbsd",
     target_os = "android"
 ))]
