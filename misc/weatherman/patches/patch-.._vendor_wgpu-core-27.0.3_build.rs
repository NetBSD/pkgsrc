$NetBSD: patch-.._vendor_wgpu-core-27.0.3_build.rs,v 1.1 2026/10/18 13:05:42 pin Exp $

Backport #8695 and #10316 to wgpu v27 series.

--- ../vendor/wgpu-core-27.0.3/build.rs.orig	2026-10-17 11:28:09.003680804 +0000
+++ ../vendor/wgpu-core-27.0.3/build.rs
@@ -1,6 +1,6 @@ fn main() {
 fn main() {
     cfg_aliases::cfg_aliases! {
-        windows_linux_android: { any(windows, target_os = "linux", target_os = "android", target_os = "freebsd") },
+        windows_linux_android: { any(windows, target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd") },
         send_sync: { all(
             feature = "std",
             any(
