$NetBSD: patch-build.rs,v 1.1 2025/12/13 17:47:21 vins Exp $

Introduce illumos support. 

--- build.rs.orig	2025-11-13 12:09:28.000000000 +0000
+++ build.rs
@@ -84,6 +84,7 @@ fn detect_cfgs(target: &mut Target) {
         ("using_cmake", &|_| option_env!("FISH_CMAKE_BINARY_DIR").is_some()),
         ("use_prebuilt_docs", &|_| env_var("FISH_USE_PREBUILT_DOCS").is_some_and(|v| v == "TRUE") ),
         ("cygwin", &detect_cygwin),
+        ("illumos", &|_| env::var("CARGO_CFG_TARGET_OS").unwrap() == "illumos"),
         ("small_main_stack", &has_small_stack),
         // See if libc supports the thread-safe localeconv_l(3) alternative to localeconv(3).
         ("localeconv_l", &|target| {
