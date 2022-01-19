$NetBSD: patch-src_ui_listview.rs,v 1.1 2022/01/19 14:04:45 pin Exp $

Fix build with rust =< 1.58.0
Patch provided by upstream

--- src/ui/listview.rs.orig	2022-01-18 21:10:09.000000000 +0000
+++ src/ui/listview.rs
@@ -85,7 +85,7 @@ impl<I: ListItem> ListView<I> {
 
     pub fn content_height_with_paginator(&self) -> usize {
         let content_len = self.content.read().unwrap().len();
-        log::info!("content len: {content_len}");
+        log::info!("content len: {}", content_len);
 
         // add 1 more row for paginator if we can paginate
         if self.can_paginate() {
@@ -97,7 +97,7 @@ impl<I: ListItem> ListView<I> {
 
     fn can_paginate(&self) -> bool {
         let loaded = self.get_pagination().loaded_content();
-        log::info!("can paginate: {loaded}");
+        log::info!("can paginate: {}", loaded);
         self.get_pagination().max_content().unwrap_or(0) > self.get_pagination().loaded_content()
     }
 
