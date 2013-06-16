$NetBSD: patch-pan_gui_header-pane.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/gui/header-pane.cc.orig	2013-06-16 10:47:35.000000000 +0000
+++ pan/gui/header-pane.cc
@@ -1256,19 +1256,19 @@ HeaderPane :: rebuild_rules (bool enable
 
   res = get_int_from_rules_str(_prefs.get_string("rules-delete-value", "never"));
   tmp.set_type_delete_b (res.first, res.second);
-  r._aggregates.push_back (tmp);
+  r._aggregates->push_back (tmp);
 
   res = get_int_from_rules_str(_prefs.get_string("rules-mark-read-value", "never"));
   tmp.set_type_mark_read_b (res.first, res.second);
-  r._aggregates.push_back (tmp);
+  r._aggregates->push_back (tmp);
 
   res = get_int_from_rules_str(_prefs.get_string("rules-autocache-value", "never"));
   tmp.set_type_autocache_b (res.first, res.second);
-  r._aggregates.push_back (tmp);
+  r._aggregates->push_back (tmp);
 
   res = get_int_from_rules_str(_prefs.get_string("rules-auto-dl-value", "never"));
   tmp.set_type_dl_b (res.first, res.second);
-   r._aggregates.push_back (tmp);
+   r._aggregates->push_back (tmp);
 
 }
 
@@ -1301,43 +1301,43 @@ HeaderPane :: rebuild_filter (const std:
       entry_filter.set_type_aggregate_or ();
       f1.set_type_text ("Subject", d);
       f2.set_type_text ("From", d);
-      entry_filter._aggregates.push_back (f1);
-      entry_filter._aggregates.push_back (f2);
+      entry_filter._aggregates->push_back (f1);
+      entry_filter._aggregates->push_back (f2);
     } else if (mode == SUBJECT_OR_AUTHOR_REGEX) {
       FilterInfo f1, f2;
       entry_filter.set_type_aggregate_or ();
       d.type = TextMatch::REGEX;
       f1.set_type_text ("Subject", d);
       f2.set_type_text ("From", d);
-      entry_filter._aggregates.push_back (f1);
-      entry_filter._aggregates.push_back (f2);
+      entry_filter._aggregates->push_back (f1);
+      entry_filter._aggregates->push_back (f2);
     }
-    f._aggregates.push_back (entry_filter);
+    f._aggregates->push_back (entry_filter);
   }
 
   if (_action_manager.is_action_active("match-only-unread-articles")) {
 //std::cerr << LINE_ID << " AND is unread" << std::endl;
     FilterInfo tmp;
     tmp.set_type_is_unread ();
-    f._aggregates.push_back (tmp);
+    f._aggregates->push_back (tmp);
   }
   if (_action_manager.is_action_active("match-only-cached-articles")) {
 //std::cerr << LINE_ID << " AND is cached" << std::endl;
     FilterInfo tmp;
     tmp.set_type_cached ();
-    f._aggregates.push_back (tmp);
+    f._aggregates->push_back (tmp);
   }
   if (_action_manager.is_action_active("match-only-binary-articles")) {
 //std::cerr << LINE_ID << " AND has an attachment" << std::endl;
     FilterInfo tmp;
     tmp.set_type_binary ();
-    f._aggregates.push_back (tmp);
+    f._aggregates->push_back (tmp);
   }
   if (_action_manager.is_action_active("match-only-my-articles")) {
 //std::cerr << LINE_ID << " AND was posted by me" << std::endl;
     FilterInfo tmp;
     tmp.set_type_posted_by_me ();
-    f._aggregates.push_back (tmp);
+    f._aggregates->push_back (tmp);
   }
 
   // try to fold the six ranges into as few FilterInfo items as possible..
@@ -1386,22 +1386,22 @@ HeaderPane :: rebuild_filter (const std:
       FilterInfo s, tmp;
       s.set_type_aggregate_and ();
       tmp.set_type_score_ge (range.first);
-      s._aggregates.push_back (tmp);
+      s._aggregates->push_back (tmp);
       tmp.set_type_score_le (range.second);
-      s._aggregates.push_back (tmp);
+      s._aggregates->push_back (tmp);
 //std::cerr << LINE_ID << " AND has a in [" << range.first << "..." << range.second << ']' << std::endl;
       filters.push_back (s);
     }
   }
   if (filters.size()==1) // can fit in an `and' parent
-    f._aggregates.push_back (filters[0]);
+    f._aggregates->push_back (filters[0]);
   else if (!filters.empty()) { // needs an `or' parent
     FilterInfo s;
     s.set_type_aggregate_or ();
-    s._aggregates.swap (filters);
-    f._aggregates.push_back (s);
+    s._aggregates->swap (filters);
+    f._aggregates->push_back (s);
   }
-//std::cerr << LINE_ID << " number of filters: " << f._aggregates.size() << std::endl;
+//std::cerr << LINE_ID << " number of filters: " << f._aggregates->size() << std::endl;
 }
 
 void
@@ -1413,7 +1413,7 @@ HeaderPane :: filter (const std::string&
   {
     _wait.watch_cursor_on ();
 
-    if (_filter._aggregates.empty())
+    if (_filter._aggregates->empty())
       _atree->set_filter ();
     else
       _atree->set_filter (_show_type, &_filter);
@@ -1431,7 +1431,7 @@ HeaderPane :: rules(bool enable)
   {
     _wait.watch_cursor_on ();
 
-    if (_rules._aggregates.empty())
+    if (_rules._aggregates->empty())
       _atree->set_rules();
     else
       _atree->set_rules(_show_type, &_rules);
