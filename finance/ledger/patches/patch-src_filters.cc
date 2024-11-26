$NetBSD: patch-src_filters.cc,v 1.1 2024/11/26 22:59:34 riastradh Exp $

Fix build with boost>=1.86, which broke API compatibility.
https://github.com/ledger/ledger/issues/2378

--- src/filters.cc.orig	2023-03-30 07:40:48.000000000 +0000
+++ src/filters.cc
@@ -238,7 +238,7 @@ void anonymize_posts::render_commodity(a
 void anonymize_posts::operator()(post_t& post)
 {
 	boost::uuids::detail::sha1  sha;
-  unsigned int message_digest[5];
+  unsigned char message_digest[20];
   bool         copy_xact_details = false;
 
   if (last_xact != post.xact) {
@@ -1268,7 +1268,7 @@ void budget_posts::report_budget_items(c
     foreach (pending_posts_list::iterator& i, posts_to_erase)
       pending_posts.erase(i);
   }
-  
+
   if (pending_posts.size() == 0)
     return;
 
