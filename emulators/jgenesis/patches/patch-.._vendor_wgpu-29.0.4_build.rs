$NetBSD: patch-.._vendor_wgpu-29.0.4_build.rs,v 1.1 2026/10/01 10:40:40 pin Exp $

Enable the GLES/OpenGL backend cfg alias on NetBSD.

--- ../vendor/wgpu-29.0.4/build.rs.orig	2026-09-17 12:45:50.020195032 +0000
+++ ../vendor/wgpu-29.0.4/build.rs
@@ -24,7 +24,7 @@ fn main() {
         gles: { any(
             // The `gles` feature enables the OpenGL/GLES backend only on "native OpenGL" platforms, i.e. Windows, Linux, Android, and Emscripten.
             // (Note that WebGL is also not included here!)
-            all(any(windows, target_os = "linux", target_os = "android", target_os = "freebsd", Emscripten), feature = "gles"),
+            all(any(windows, target_os = "linux", target_os = "android", target_os = "freebsd", target_os = "netbsd", Emscripten), feature = "gles"),
             // On Apple platforms, however, we require the `angle` feature to explicitly opt-in to OpenGL
             // since its meant to be used with ANGLE.
             all(target_vendor = "apple", feature = "angle")
