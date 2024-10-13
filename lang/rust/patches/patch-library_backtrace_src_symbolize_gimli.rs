$NetBSD: patch-library_backtrace_src_symbolize_gimli.rs,v 1.7 2024/10/13 19:04:39 he Exp $

Add NetBSD to the family who is in the unix class.

--- library/backtrace/src/symbolize/gimli.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ library/backtrace/src/symbolize/gimli.rs
@@ -40,6 +40,7 @@ cfg_if::cfg_if! {
         target_os = "haiku",
         target_os = "hurd",
         target_os = "linux",
+        target_os = "netbsd",
         target_os = "openbsd",
         target_os = "solaris",
         target_os = "illumos",
