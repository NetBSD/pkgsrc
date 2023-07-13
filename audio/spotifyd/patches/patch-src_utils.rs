$NetBSD: patch-src_utils.rs,v 1.1 2023/07/13 20:38:53 pin Exp $

Allow building on NetBSD.

--- src/utils.rs.orig	2023-04-20 21:37:30.000000000 +0000
+++ src/utils.rs
@@ -1,7 +1,7 @@
 use log::trace;
 use std::env;
 
-#[cfg(any(target_os = "freebsd", target_os = "linux"))]
+#[cfg(any(target_os = "netbsd", target_os = "freebsd", target_os = "linux"))]
 fn get_shell_ffi() -> Option<String> {
     use libc::{geteuid, getpwuid_r};
     use std::{ffi::CStr, mem, ptr};
