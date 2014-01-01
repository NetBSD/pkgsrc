$NetBSD: patch-pan_data-impl_rules-filter.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/data-impl/rules-filter.cc.orig	2013-12-21 12:39:24.000000000 +0000
+++ pan/data-impl/rules-filter.cc
@@ -62,8 +62,8 @@ RulesFilter :: test_article ( Data      
   {
     case RulesInfo::AGGREGATE__AND:
       pass = true;
-      foreach (RulesInfo::aggregates_t, rules._aggregates, it)
-        test_article (data, *it, group, article);
+      foreach (RulesInfo::aggregatesp_t, rules._aggregates, it)
+        test_article (data, **it, group, article);
       break;
 
     case RulesInfo::AGGREGATE__OR:
@@ -71,8 +71,8 @@ RulesFilter :: test_article ( Data      
         pass = true;
       else {
         pass = false;
-        foreach (RulesInfo::aggregates_t, rules._aggregates, it) {
-          if (test_article (data, *it, group, article)) {
+        foreach (RulesInfo::aggregatesp_t, rules._aggregates, it) {
+          if (test_article (data, **it, group, article)) {
             pass = true;
             break;
           }
