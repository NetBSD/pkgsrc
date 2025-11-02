$NetBSD: patch-build.rs,v 1.1 2025/11/02 18:44:06 vins Exp $

Introduce illumos support. 

--- build.rs.orig	2025-11-01 17:24:40.473636720 +0000
+++ build.rs
@@ -84,6 +84,7 @@ fn detect_cfgs(target: &mut Target) {
         ("apple", &detect_apple),
         ("bsd", &detect_bsd),
         ("cygwin", &detect_cygwin),
+        ("illumos", &|_| env::var("CARGO_CFG_TARGET_OS").unwrap() == "illumos"),
         ("small_main_stack", &has_small_stack),
         // See if libc supports the thread-safe localeconv_l(3) alternative to localeconv(3).
         ("localeconv_l", &|target| {
