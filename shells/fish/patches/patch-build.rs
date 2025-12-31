$NetBSD: patch-build.rs,v 1.2 2025/12/31 00:47:58 ktnb Exp $

Introduce illumos support. 

--- build.rs.orig	2025-12-28 15:54:44.000000000 +0000
+++ build.rs
@@ -76,6 +76,7 @@ fn detect_cfgs(target: &mut Target) {
         ("apple", &(|_| target_os_is_apple())),
         ("bsd", &(|_| target_os_is_bsd())),
         ("cygwin", &(|_| target_os_is_cygwin())),
+        ("illumos", &|_| env::var("CARGO_CFG_TARGET_OS").unwrap() == "illumos"),
         ("have_eventfd", &|target| {
             // FIXME: NetBSD 10 has eventfd, but the libc crate does not expose it.
             if target_os() == "netbsd" {
