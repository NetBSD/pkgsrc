$NetBSD: patch-pan_data-impl_article-filter.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/data-impl/article-filter.cc.orig	2013-12-21 12:38:33.000000000 +0000
+++ pan/data-impl/article-filter.cc
@@ -62,10 +62,10 @@ ArticleFilter :: test_article (const Dat
   {
     case FilterInfo::AGGREGATE_AND:
       pass = true;
-      foreach_const (FilterInfo::aggregates_t, criteria._aggregates, it) {
+      foreach_const (FilterInfo::aggregatesp_t, criteria._aggregates, it) {
         // assume test passes if test needs body but article not cached
-        if (!it->_needs_body || cache.contains(article.message_id) )
-          if (!test_article (data, *it, group, article)) {
+        if (!(*it)->_needs_body || cache.contains(article.message_id) )
+          if (!test_article (data, **it, group, article)) {
             pass = false;
             break;
           }
@@ -77,10 +77,10 @@ ArticleFilter :: test_article (const Dat
         pass = true;
       else {
         pass = false;
-        foreach_const (FilterInfo::aggregates_t, criteria._aggregates, it) {
+        foreach_const (FilterInfo::aggregatesp_t, criteria._aggregates, it) {
           // assume test fails if test needs body but article not cached
-          if (!it->_needs_body || cache.contains(article.message_id) )
-            if (test_article (data, *it, group, article)) {
+          if (!(*it)->_needs_body || cache.contains(article.message_id) )
+            if (test_article (data, **it, group, article)) {
               pass = true;
               break;
             }
