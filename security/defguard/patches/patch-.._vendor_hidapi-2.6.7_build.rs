$NetBSD: patch-.._vendor_hidapi-2.6.7_build.rs,v 1.1 2026/11/09 08:14:56 adam Exp $

Support NetBSD.
https://github.com/ruabmbua/hidapi-rs/issues/188

--- ../vendor/hidapi-2.6.7/build.rs.orig	2026-11-06 14:16:24.791034121 +0000
+++ ../vendor/hidapi-2.6.7/build.rs
@@ -36,6 +36,8 @@ fn main() {
         compile_macos();
     } else if target.contains("freebsd") {
         compile_freebsd();
+    } else if target.contains("netbsd") {
+        compile_openbsd();
     } else if target.contains("openbsd") {
         compile_openbsd();
     } else if target.contains("illumos") {
