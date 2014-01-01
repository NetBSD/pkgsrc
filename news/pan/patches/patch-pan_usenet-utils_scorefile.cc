$NetBSD: patch-pan_usenet-utils_scorefile.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/usenet-utils/scorefile.cc.orig	2013-12-21 12:33:23.000000000 +0000
+++ pan/usenet-utils/scorefile.cc
@@ -103,7 +103,7 @@ struct pan::Scorefile::ParseContext
       test = &item->test;
     if (test)
       foreach_const (std::vector<int>, test_offsets, it)
-        test = &test->_aggregates[*it];
+        test = test->_aggregates[*it];
     return test;
   }
 
@@ -258,11 +258,11 @@ Scorefile :: parse_file (ParseContext& c
 
       line.eat_chars (1); // skip past the '{'
       const bool only_one_test_must_pass (line.len>=2 && !memcmp(line.str,"::",2));
-      FilterInfo test;
+      FilterInfo *test = new FilterInfo;
       if (only_one_test_must_pass)
-        test.set_type_aggregate_or ();
+        test->set_type_aggregate_or ();
       else
-        test.set_type_aggregate_and ();
+        test->set_type_aggregate_and ();
 
       FilterInfo * parent (context.get_current_test ());
       context.test_offsets.push_back (parent->_aggregates.size());
@@ -331,9 +331,9 @@ Scorefile :: parse_file (ParseContext& c
       StringView val (line.substr (delimiter+1, 0));
       val.trim ();
 
-      FilterInfo::aggregates_t& aggregates (context.get_current_test()->_aggregates);
+      FilterInfo::aggregatesp_t& aggregates (context.get_current_test()->_aggregates);
       aggregates.resize (aggregates.size() + 1);
-      FilterInfo& test (aggregates.back());
+      FilterInfo* test (aggregates.back());
  
       if (!key.strncasecmp ("Lines", 5))
       {
@@ -341,26 +341,26 @@ Scorefile :: parse_file (ParseContext& c
         // "~Lines: 5" matches articles with <= 5 lines.
         const unsigned long gt = strtoul (val.str, NULL, 10);
         const unsigned long ge = gt + 1;
-        test.set_type_line_count_ge (ge);
+        test->set_type_line_count_ge (ge);
       }
       else if (!key.strncasecmp("Bytes", 5))
       {
         // bytes works the same way as lines.
         const unsigned long gt = strtoul (val.str, NULL, 10);
         const unsigned long ge = gt + 1;
-        test.set_type_byte_count_ge (ge);
+        test->set_type_byte_count_ge (ge);
       }
       else if (!key.strncasecmp ("Age", 3))
       {
         // age works differently from Lines and Bytes:
         // "Age: 7" matches articles <= 7 days old.
         const unsigned long le = strtoul (val.str, NULL, 10);
-        test.set_type_days_old_le (le);
+        test->set_type_days_old_le (le);
         negate = !negate; // double negative: le is a negate state
       }
       else if (!key.strncasecmp ("Has-Body", 8))
       {
-        test.set_type_cached ();
+        test->set_type_cached ();
         if (val == "0")
           negate = !negate;
       }
@@ -370,9 +370,9 @@ Scorefile :: parse_file (ParseContext& c
         d.type = TextMatch::REGEX;
         d.case_sensitive = case_sensitive;
         d.text.assign (val.str, val.len);
-        test.set_type_text (key, d);
+        test->set_type_text (key, d);
       }
-      test._negate = negate;
+      test->_negate = negate;
     }
 
     // error
@@ -396,9 +396,9 @@ namespace
       return;
 
     if (test._aggregates.size() == 1)
-      test = test._aggregates[0];
-    else foreach (FilterInfo::aggregates_t, test._aggregates, it)
-      normalize_test (*it);
+      test = *test._aggregates[0];
+    else foreach (FilterInfo::aggregatesp_t, test._aggregates, it)
+      normalize_test (**it);
   }
 }
 
