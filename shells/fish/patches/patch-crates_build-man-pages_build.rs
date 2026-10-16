$NetBSD: patch-crates_build-man-pages_build.rs,v 1.1 2026/10/16 09:52:48 wiz Exp $

Do not spawn more processes than pkgsrc intends.

--- crates/build-man-pages/build.rs.orig	2026-10-16 09:44:47.007948825 +0000
+++ crates/build-man-pages/build.rs
@@ -27,8 +27,6 @@ fn build_man(sec1_dir: &Path) {
     ]);
 
     let args = as_os_strs![
-        "-j",
-        "auto",
         "-q",
         "-b",
         "man",
