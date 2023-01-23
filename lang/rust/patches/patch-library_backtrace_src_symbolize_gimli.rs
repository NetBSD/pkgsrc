$NetBSD: patch-library_backtrace_src_symbolize_gimli.rs,v 1.3 2023/01/23 18:49:04 he Exp $

Add NetBSD to the family who uses dl_iterate_phdr().

--- library/backtrace/src/symbolize/gimli.rs.orig	2022-04-04 09:41:26.000000000 +0000
+++ library/backtrace/src/symbolize/gimli.rs
@@ -177,6 +177,7 @@ cfg_if::cfg_if! {
             target_os = "linux",
             target_os = "fuchsia",
             target_os = "freebsd",
+            target_os = "netbsd",
             target_os = "openbsd",
             all(target_os = "android", feature = "dl_iterate_phdr"),
         ),
