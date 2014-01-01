$NetBSD: patch-pan_gui_header-pane.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/gui/header-pane.cc.orig	2013-12-21 12:40:58.000000000 +0000
+++ pan/gui/header-pane.cc
@@ -1250,26 +1250,29 @@ HeaderPane :: rebuild_rules (bool enable
 
   RulesInfo &r (_rules);
   r.set_type_aggregate_and ();
-  RulesInfo tmp;
+  RulesInfo *tmp;
 
   std::pair<int,int> res;
 
+  tmp = new RulesInfo;
   res = get_int_from_rules_str(_prefs.get_string("rules-delete-value", "never"));
-  tmp.set_type_delete_b (res.first, res.second);
+  tmp->set_type_delete_b (res.first, res.second);
   r._aggregates.push_back (tmp);
 
+  tmp = new RulesInfo;
   res = get_int_from_rules_str(_prefs.get_string("rules-mark-read-value", "never"));
-  tmp.set_type_mark_read_b (res.first, res.second);
+  tmp->set_type_mark_read_b (res.first, res.second);
   r._aggregates.push_back (tmp);
 
+  tmp = new RulesInfo;
   res = get_int_from_rules_str(_prefs.get_string("rules-autocache-value", "never"));
-  tmp.set_type_autocache_b (res.first, res.second);
+  tmp->set_type_autocache_b (res.first, res.second);
   r._aggregates.push_back (tmp);
 
+  tmp = new RulesInfo;
   res = get_int_from_rules_str(_prefs.get_string("rules-auto-dl-value", "never"));
-  tmp.set_type_dl_b (res.first, res.second);
-   r._aggregates.push_back (tmp);
-
+  tmp->set_type_dl_b (res.first, res.second);
+  r._aggregates.push_back (tmp);
 }
 
 void
@@ -1287,56 +1290,56 @@ HeaderPane :: rebuild_filter (const std:
   f.set_type_aggregate_and ();
 
   // entry field filter...
-  FilterInfo entry_filter;
   if (!text.empty())
   {
+    FilterInfo *entry_filter = new FilterInfo;
     if (mode == SUBJECT)
-      entry_filter.set_type_text ("Subject", d);
+      entry_filter->set_type_text ("Subject", d);
     else if (mode == AUTHOR)
-      entry_filter.set_type_text ("From", d);
+      entry_filter->set_type_text ("From", d);
     else if (mode == MESSAGE_ID)
-      entry_filter.set_type_text ("Message-ID", d);
+      entry_filter->set_type_text ("Message-ID", d);
     else if (mode == SUBJECT_OR_AUTHOR) {
-      FilterInfo f1, f2;
-      entry_filter.set_type_aggregate_or ();
-      f1.set_type_text ("Subject", d);
-      f2.set_type_text ("From", d);
-      entry_filter._aggregates.push_back (f1);
-      entry_filter._aggregates.push_back (f2);
+      FilterInfo *f1 = new FilterInfo, *f2 = new FilterInfo;
+      entry_filter->set_type_aggregate_or ();
+      f1->set_type_text ("Subject", d);
+      f2->set_type_text ("From", d);
+      entry_filter->_aggregates.push_back (f1);
+      entry_filter->_aggregates.push_back (f2);
     } else if (mode == SUBJECT_OR_AUTHOR_REGEX) {
-      FilterInfo f1, f2;
-      entry_filter.set_type_aggregate_or ();
+      FilterInfo *f1 = new FilterInfo, *f2 = new FilterInfo;
+      entry_filter->set_type_aggregate_or ();
       d.type = TextMatch::REGEX;
-      f1.set_type_text ("Subject", d);
-      f2.set_type_text ("From", d);
-      entry_filter._aggregates.push_back (f1);
-      entry_filter._aggregates.push_back (f2);
+      f1->set_type_text ("Subject", d);
+      f2->set_type_text ("From", d);
+      entry_filter->_aggregates.push_back (f1);
+      entry_filter->_aggregates.push_back (f2);
     }
     f._aggregates.push_back (entry_filter);
   }
 
   if (_action_manager.is_action_active("match-only-unread-articles")) {
 //std::cerr << LINE_ID << " AND is unread" << std::endl;
-    FilterInfo tmp;
-    tmp.set_type_is_unread ();
+    FilterInfo *tmp = new FilterInfo;
+    tmp->set_type_is_unread ();
     f._aggregates.push_back (tmp);
   }
   if (_action_manager.is_action_active("match-only-cached-articles")) {
 //std::cerr << LINE_ID << " AND is cached" << std::endl;
-    FilterInfo tmp;
-    tmp.set_type_cached ();
+    FilterInfo *tmp = new FilterInfo;
+    tmp->set_type_cached ();
     f._aggregates.push_back (tmp);
   }
   if (_action_manager.is_action_active("match-only-binary-articles")) {
 //std::cerr << LINE_ID << " AND has an attachment" << std::endl;
-    FilterInfo tmp;
-    tmp.set_type_binary ();
+    FilterInfo *tmp = new FilterInfo;
+    tmp->set_type_binary ();
     f._aggregates.push_back (tmp);
   }
   if (_action_manager.is_action_active("match-only-my-articles")) {
 //std::cerr << LINE_ID << " AND was posted by me" << std::endl;
-    FilterInfo tmp;
-    tmp.set_type_posted_by_me ();
+    FilterInfo *tmp = new FilterInfo;
+    tmp->set_type_posted_by_me ();
     f._aggregates.push_back (tmp);
   }
 
@@ -1365,7 +1368,7 @@ HeaderPane :: rebuild_filter (const std:
 
 //for (size_t i=0; i<ranges.size(); ++i) std::cerr << LINE_ID << " range [" << ranges[i].first << "..." << ranges[i].second << "]" << std::endl;
 
-  std::deque<FilterInfo> filters;
+  FilterInfo::aggregatesp_t filters;
   for (size_t i=0; i<ranges.size(); ++i) {
     const range_t& range (ranges[i]);
     const bool low_bound (range.first == INT_MIN);
@@ -1373,22 +1376,24 @@ HeaderPane :: rebuild_filter (const std:
     if (low_bound && hi_bound) {
       // everything matches -- do nothing
     } else if (hi_bound) {
-      FilterInfo tmp;
-      tmp.set_type_score_ge (range.first);
+      FilterInfo *tmp = new FilterInfo;
+      tmp->set_type_score_ge (range.first);
 //std::cerr << LINE_ID << " AND has a score >= " << range.first << std::endl;
       filters.push_back (tmp);
     } else if (low_bound) {
-      FilterInfo tmp;
-      tmp.set_type_score_le (range.second);
+      FilterInfo *tmp = new FilterInfo;
+      tmp->set_type_score_le (range.second);
 //std::cerr << LINE_ID << " AND has a score <= " << range.second << std::endl;
       filters.push_back (tmp);
     } else  { // not bound on either side; need an aggregate
-      FilterInfo s, tmp;
-      s.set_type_aggregate_and ();
-      tmp.set_type_score_ge (range.first);
-      s._aggregates.push_back (tmp);
-      tmp.set_type_score_le (range.second);
-      s._aggregates.push_back (tmp);
+      FilterInfo *tmp, *s = new FilterInfo;
+      s->set_type_aggregate_and ();
+      tmp = new FilterInfo;
+      tmp->set_type_score_ge (range.first);
+      s->_aggregates.push_back (tmp);
+      tmp = new FilterInfo;
+      tmp->set_type_score_le (range.second);
+      s->_aggregates.push_back (tmp);
 //std::cerr << LINE_ID << " AND has a in [" << range.first << "..." << range.second << ']' << std::endl;
       filters.push_back (s);
     }
@@ -1396,9 +1401,9 @@ HeaderPane :: rebuild_filter (const std:
   if (filters.size()==1) // can fit in an `and' parent
     f._aggregates.push_back (filters[0]);
   else if (!filters.empty()) { // needs an `or' parent
-    FilterInfo s;
-    s.set_type_aggregate_or ();
-    s._aggregates.swap (filters);
+    FilterInfo *s = new FilterInfo;
+    s->set_type_aggregate_or ();
+    s->_aggregates.swap (filters);
     f._aggregates.push_back (s);
   }
 //std::cerr << LINE_ID << " number of filters: " << f._aggregates.size() << std::endl;
