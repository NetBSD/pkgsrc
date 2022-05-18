$NetBSD: patch-vendor_backtrace_src_symbolize_gimli.rs,v 1.1 2022/05/18 20:57:28 he Exp $

Do mmap and dl_iterate_phdr() on NetBSD as well.

--- vendor/backtrace/src/symbolize/gimli.rs.orig	2022-02-23 05:34:24.000000000 +0000
+++ vendor/backtrace/src/symbolize/gimli.rs
@@ -38,6 +38,7 @@ cfg_if::cfg_if! {
         target_os = "ios",
         target_os = "linux",
         target_os = "macos",
+        target_os = "netbsd",
         target_os = "openbsd",
         target_os = "solaris",
         target_os = "illumos",
@@ -177,6 +178,7 @@ cfg_if::cfg_if! {
             target_os = "linux",
             target_os = "fuchsia",
             target_os = "freebsd",
+            target_os = "netbsd",
             target_os = "openbsd",
             all(target_os = "android", feature = "dl_iterate_phdr"),
         ),
