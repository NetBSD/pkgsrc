$NetBSD: patch-src_output_render_mod.rs,v 1.1 2023/12/30 03:08:48 fox Exp $

Patch out incorrect call to fflagstostr(3) in NetBSD to avoid build breakage.

The proper fix would be to update upstream to use flags_to_string(3) from libutil

--- src/output/render/mod.rs.orig	2023-12-30 02:31:49.829005853 +0000
+++ src/output/render/mod.rs
@@ -49,7 +49,6 @@ pub use self::securityctx::Colours as Se
 #[cfg(any(
     target_os = "macos",
     target_os = "freebsd",
-    target_os = "netbsd",
     target_os = "openbsd",
     target_os = "dragonfly"
 ))]
@@ -61,7 +60,6 @@ mod flags_windows;
 #[cfg(not(any(
     target_os = "macos",
     target_os = "freebsd",
-    target_os = "netbsd",
     target_os = "openbsd",
     target_os = "dragonfly",
     target_os = "windows"
