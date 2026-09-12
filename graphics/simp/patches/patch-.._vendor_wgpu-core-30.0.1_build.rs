$NetBSD: patch-.._vendor_wgpu-core-30.0.1_build.rs,v 1.1 2026/09/12 17:41:30 pin Exp $

Enable the GLES/OpenGL backend cfg alias on NetBSD.

--- ../vendor/wgpu-core-30.0.1/build.rs.orig	2026-09-12 14:02:00.393267003 +0000
+++ ../vendor/wgpu-core-30.0.1/build.rs
@@ -1,6 +1,6 @@ fn main() {
 fn main() {
     cfg_aliases::cfg_aliases! {
-        windows_linux_android: { any(windows, target_os = "linux", target_os = "android", target_os = "freebsd") },
+        windows_linux_android: { any(windows, target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd") },
         send_sync: { all(
             feature = "std",
             any(
