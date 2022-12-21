$NetBSD: patch-vendor_tree__magic__mini-3.0.3_src_fdo__magic_builtin_init.rs,v 1.1 2022/12/21 14:19:42 pin Exp $

Don't pull from a specific pull-request.
Patch tree_magic_mini crate within pkgsrc.

--- ../vendor/tree_magic_mini-3.0.3/src/fdo_magic/builtin/init.rs.orig	1973-11-29 21:33:09.000000000 +0000
+++ ../vendor/tree_magic_mini-3.0.3/src/fdo_magic/builtin/init.rs
@@ -21,11 +21,15 @@ fn subclasses() -> &'static str {
 pub fn get_aliaslist() -> FnvHashMap<MIME, MIME> {
     aliases()
         .lines()
-        .map(|line| {
-            let mut parts = line.split_whitespace();
-            let a = parts.next().unwrap();
-            let b = parts.next().unwrap();
-            (a, b)
+        .filter_map(|line| {
+            if !line.is_empty() {
+                let mut parts = line.split_whitespace();
+                let a = parts.next().unwrap();
+                let b = parts.next().unwrap();
+                Some((a, b))
+            } else {
+                None
+            }
         })
         .collect()
 }
@@ -39,16 +43,20 @@ pub fn get_supported() -> Vec<MIME> {
 pub fn get_subclasses() -> Vec<(MIME, MIME)> {
     subclasses()
         .lines()
-        .map(|line| {
-            let mut parts = line.split_whitespace();
+        .filter_map(|line| {
+            if !line.is_empty() {
+                let mut parts = line.split_whitespace();
 
-            let child = parts.next().unwrap();
-            let child = super::ALIASES.get(child).copied().unwrap_or(child);
+                let child = parts.next().unwrap();
+                let child = super::ALIASES.get(child).copied().unwrap_or(child);
 
-            let parent = parts.next().unwrap();
-            let parent = super::ALIASES.get(parent).copied().unwrap_or(parent);
+                let parent = parts.next().unwrap();
+                let parent = super::ALIASES.get(parent).copied().unwrap_or(parent);
 
-            (parent, child)
+            Some((parent, child))
+            } else {
+                None
+            }
         })
         .collect()
 }
