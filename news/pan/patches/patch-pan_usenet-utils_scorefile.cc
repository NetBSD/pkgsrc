$NetBSD: patch-pan_usenet-utils_scorefile.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/usenet-utils/scorefile.cc.orig	2013-06-16 10:40:34.000000000 +0000
+++ pan/usenet-utils/scorefile.cc
@@ -103,7 +103,7 @@ struct pan::Scorefile::ParseContext
       test = &item->test;
     if (test)
       foreach_const (std::vector<int>, test_offsets, it)
-        test = &test->_aggregates[*it];
+        test = &(*test->_aggregates)[*it];
     return test;
   }
 
@@ -265,8 +265,8 @@ Scorefile :: parse_file (ParseContext& c
         test.set_type_aggregate_and ();
 
       FilterInfo * parent (context.get_current_test ());
-      context.test_offsets.push_back (parent->_aggregates.size());
-      parent->_aggregates.push_back (test);
+      context.test_offsets.push_back (parent->_aggregates->size());
+      parent->_aggregates->push_back (test);
     }
 
     // end nested conditions
@@ -331,7 +331,7 @@ Scorefile :: parse_file (ParseContext& c
       StringView val (line.substr (delimiter+1, 0));
       val.trim ();
 
-      FilterInfo::aggregates_t& aggregates (context.get_current_test()->_aggregates);
+      FilterInfo::aggregates_t& aggregates (*context.get_current_test()->_aggregates);
       aggregates.resize (aggregates.size() + 1);
       FilterInfo& test (aggregates.back());
  
@@ -395,9 +395,9 @@ namespace
     if ((test._type!=test.AGGREGATE_AND) && (test._type!=test.AGGREGATE_OR))
       return;
 
-    if (test._aggregates.size() == 1)
-      test = test._aggregates[0];
-    else foreach (FilterInfo::aggregates_t, test._aggregates, it)
+    if (test._aggregates->size() == 1)
+      test = (*test._aggregates)[0];
+    else foreach (FilterInfo::aggregates_t, *test._aggregates, it)
       normalize_test (*it);
   }
 }
