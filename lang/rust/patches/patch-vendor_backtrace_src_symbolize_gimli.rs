$NetBSD: patch-vendor_backtrace_src_symbolize_gimli.rs,v 1.2 2022/08/30 19:22:17 he Exp $

Do mmap on NetBSD as well.

--- ./vendor/backtrace/src/symbolize/gimli.rs.orig	2022-04-04 11:10:55.000000000 +0000
+++ ./vendor/backtrace/src/symbolize/gimli.rs
@@ -38,6 +38,7 @@ cfg_if::cfg_if! {
         target_os = "ios",
         target_os = "linux",
         target_os = "macos",
+        target_os = "netbsd",
         target_os = "openbsd",
         target_os = "solaris",
         target_os = "illumos",
