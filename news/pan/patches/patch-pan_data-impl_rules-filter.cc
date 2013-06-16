$NetBSD: patch-pan_data-impl_rules-filter.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/data-impl/rules-filter.cc.orig	2013-06-16 10:44:22.000000000 +0000
+++ pan/data-impl/rules-filter.cc
@@ -62,16 +62,16 @@ RulesFilter :: test_article ( Data      
   {
     case RulesInfo::AGGREGATE__AND:
       pass = true;
-      foreach (RulesInfo::aggregates_t, rules._aggregates, it)
+      foreach (RulesInfo::aggregates_t, *rules._aggregates, it)
         test_article (data, *it, group, article);
       break;
 
     case RulesInfo::AGGREGATE__OR:
-      if (rules._aggregates.empty())
+      if (rules._aggregates->empty())
         pass = true;
       else {
         pass = false;
-        foreach (RulesInfo::aggregates_t, rules._aggregates, it) {
+        foreach (RulesInfo::aggregates_t, *rules._aggregates, it) {
           if (test_article (data, *it, group, article)) {
             pass = true;
             break;
