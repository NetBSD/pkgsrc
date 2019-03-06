$NetBSD: patch-src_tools_tidy_src_features.rs,v 1.1 2019/03/06 16:51:53 rin Exp $

Fix build for rust 1.33.0;
trim_left_matches has been superseded by trim_start_matches.

--- src/tools/tidy/src/features.rs.orig	2019-03-07 00:36:26.836890152 +0900
+++ src/tools/tidy/src/features.rs	2019-03-07 00:36:45.715999809 +0900
@@ -188,7 +188,7 @@ pub fn collect_lang_features(base_src_pa
             }
 
             let mut parts = line.split(',');
-            let level = match parts.next().map(|l| l.trim().trim_left_matches('(')) {
+            let level = match parts.next().map(|l| l.trim().trim_start_matches('(')) {
                 Some("active") => Status::Unstable,
                 Some("removed") => Status::Removed,
                 Some("accepted") => Status::Stable,
