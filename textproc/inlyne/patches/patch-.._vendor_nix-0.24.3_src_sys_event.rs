$NetBSD: patch-.._vendor_nix-0.24.3_src_sys_event.rs,v 1.1 2026/08/07 09:30:45 pin Exp $

Fix type_of_udata group for newer libc.

--- ../vendor/nix-0.24.3/src/sys/event.rs.orig	2026-08-07 07:30:11.300092617 +0000
+++ ../vendor/nix-0.24.3/src/sys/event.rs
@@ -19,13 +19,11 @@ pub struct KEvent {
 
 #[cfg(any(target_os = "dragonfly", target_os = "freebsd",
           target_os = "ios", target_os = "macos",
-          target_os = "openbsd"))]
+          target_os = "netbsd", target_os = "openbsd"))]
 type type_of_udata = *mut libc::c_void;
 #[cfg(any(target_os = "dragonfly", target_os = "freebsd",
           target_os = "ios", target_os = "macos"))]
 type type_of_data = intptr_t;
-#[cfg(any(target_os = "netbsd"))]
-type type_of_udata = intptr_t;
 #[cfg(any(target_os = "netbsd", target_os = "openbsd"))]
 type type_of_data = i64;
 
