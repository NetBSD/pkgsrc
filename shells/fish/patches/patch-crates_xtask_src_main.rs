$NetBSD: patch-crates_xtask_src_main.rs,v 1.1 2026/10/16 09:52:48 wiz Exp $

Do not spawn more processes than pkgsrc intends.

--- crates/xtask/src/main.rs.orig	2026-10-16 09:49:27.410776573 +0000
+++ crates/xtask/src/main.rs
@@ -122,8 +122,6 @@ fn build_html_docs(fish_indent: Option<PathBuf>) -> Re
     let doctrees_dir = fish_build_helper::fish_doc_dir().join(".doctrees-html");
     let html_dir = fish_build_helper::fish_doc_dir().join("html");
     let args = as_os_strs![
-        "-j",
-        "auto",
         "-q",
         "-b",
         "html",
