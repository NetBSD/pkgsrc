$NetBSD: patch-pan_general_log.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/general/log.cc.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/general/log.cc
@@ -68,7 +68,11 @@ Log :: add_entry(Entry& e, std::deque<En
   a.date = time(NULL);
   a.severity = e.severity;
   a.message = e.message;
-  a.messages = list;
+  foreach (std::deque<Entry>, list, it)
+  {
+    Entry* new_entry = new Entry(*it);
+    a.messages.push_back(new_entry);
+  }
   fire_entry_added (a);
 }
 
