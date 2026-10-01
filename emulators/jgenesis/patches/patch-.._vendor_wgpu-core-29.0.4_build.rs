$NetBSD: patch-.._vendor_wgpu-core-29.0.4_build.rs,v 1.1 2026/10/01 10:40:40 pin Exp $

Enable the GLES/OpenGL backend cfg alias on NetBSD.

--- ../vendor/wgpu-core-29.0.4/build.rs.orig	2026-09-17 12:47:28.988180809 +0000
+++ ../vendor/wgpu-core-29.0.4/build.rs
@@ -1,6 +1,6 @@ fn main() {
 fn main() {
     cfg_aliases::cfg_aliases! {
-        windows_linux_android: { any(windows, target_os = "linux", target_os = "android", target_os = "freebsd") },
+        windows_linux_android: { any(windows, target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd") },
         send_sync: { all(
             feature = "std",
             any(
