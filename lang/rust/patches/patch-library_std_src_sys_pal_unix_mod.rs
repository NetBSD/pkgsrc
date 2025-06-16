$NetBSD: patch-library_std_src_sys_pal_unix_mod.rs,v 1.3 2025/06/16 21:10:44 he Exp $

Add libexecinfo for backtrace() on NetBSD.

--- library/std/src/sys/pal/unix/mod.rs.orig	2025-03-31 21:37:24.000000000 +0000
+++ library/std/src/sys/pal/unix/mod.rs
@@ -379,6 +379,7 @@ cfg_if::cfg_if! {
         #[link(name = "pthread")]
         unsafe extern "C" {}
     } else if #[cfg(target_os = "netbsd")] {
+        #[link(name = "execinfo")]
         #[link(name = "pthread")]
         #[link(name = "rt")]
         unsafe extern "C" {}
