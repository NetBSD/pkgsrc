$NetBSD: patch-src_wildcard.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

Prevent type clash on SunOS.

--- src/wildcard.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/wildcard.rs
@@ -379,7 +379,7 @@ fn wildcard_test_flags_then_complete(
     // regular file *excludes* broken links - we have no use for them as commands.
     let is_regular_file = entry
         .check_type()
-        .map(|x| x == DirEntryType::reg)
+        .map(|x| x == DirEntryType::regr)
         .unwrap_or(false);
     if executables_only && (!is_regular_file || waccess(filepath, X_OK) != 0) {
         return false;
