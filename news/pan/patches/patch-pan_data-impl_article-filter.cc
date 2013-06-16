$NetBSD: patch-pan_data-impl_article-filter.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/data-impl/article-filter.cc.orig	2013-06-16 10:43:31.000000000 +0000
+++ pan/data-impl/article-filter.cc
@@ -62,7 +62,7 @@ ArticleFilter :: test_article (const Dat
   {
     case FilterInfo::AGGREGATE_AND:
       pass = true;
-      foreach_const (FilterInfo::aggregates_t, criteria._aggregates, it) {
+      foreach_const (FilterInfo::aggregates_t, *criteria._aggregates, it) {
         // assume test passes if test needs body but article not cached
         if (!it->_needs_body || cache.contains(article.message_id) )
           if (!test_article (data, *it, group, article)) {
@@ -73,11 +73,11 @@ ArticleFilter :: test_article (const Dat
       break;
 
     case FilterInfo::AGGREGATE_OR:
-      if (criteria._aggregates.empty())
+      if (criteria._aggregates->empty())
         pass = true;
       else {
         pass = false;
-        foreach_const (FilterInfo::aggregates_t, criteria._aggregates, it) {
+        foreach_const (FilterInfo::aggregates_t, *criteria._aggregates, it) {
           // assume test fails if test needs body but article not cached
           if (!it->_needs_body || cache.contains(article.message_id) )
             if (test_article (data, *it, group, article)) {
