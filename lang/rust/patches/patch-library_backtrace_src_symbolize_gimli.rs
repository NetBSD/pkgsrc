$NetBSD: patch-library_backtrace_src_symbolize_gimli.rs,v 1.6 2024/04/18 09:29:42 pin Exp $

Add NetBSD to the family who is in the unix class.

--- library/backtrace/src/symbolize/gimli.rs.orig	2022-04-04 09:41:26.000000000 +0000
+++ library/backtrace/src/symbolize/gimli.rs
@@ -38,6 +38,7 @@ cfg_if::cfg_if! {
         target_os = "ios",
         target_os = "linux",
         target_os = "macos",
+        target_os = "netbsd",
         target_os = "openbsd",
         target_os = "solaris",
         target_os = "illumos",
