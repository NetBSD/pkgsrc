$NetBSD: patch-vendor_syntect-5.0.0_src_util.rs,v 1.1 2022/11/12 21:58:32 pin Exp $

Don't pull from git, patch vendor crate instead.

--- ../vendor/syntect-5.0.0/src/util.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/syntect-5.0.0/src/util.rs
@@ -247,7 +247,11 @@ pub fn split_at<'a, A: Clone>(v: &[(A, &
     let mut after = Vec::new();
     // If necessary, split the token the split falls inside
     if !rest.is_empty() && rest_split_i > 0 {
-        let (sa, sb) = rest[0].1.split_at(rest_split_i);
+        let mut rest_split_index = rest_split_i;
+        while !rest[0].1.is_char_boundary(rest_split_index) && rest_split_index > 0 {
+            rest_split_index -= 1;
+        }
+        let (sa, sb) = rest[0].1.split_at(rest_split_index);
         before.push((rest[0].0.clone(), sa));
         after.push((rest[0].0.clone(), sb));
         rest = &rest[1..];
