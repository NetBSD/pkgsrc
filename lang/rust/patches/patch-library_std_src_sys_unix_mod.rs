$NetBSD: patch-library_std_src_sys_unix_mod.rs,v 1.4 2022/01/21 23:20:36 he Exp $

Add libexecinfo for backtrace() on NetBSD.

--- library/std/src/sys/unix/mod.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ library/std/src/sys/unix/mod.rs
@@ -269,6 +269,7 @@ cfg_if::cfg_if! {
         #[link(name = "pthread")]
         extern "C" {}
     } else if #[cfg(target_os = "netbsd")] {
+        #[link(name = "execinfo")]
         #[link(name = "pthread")]
         #[link(name = "rt")]
         extern "C" {}
