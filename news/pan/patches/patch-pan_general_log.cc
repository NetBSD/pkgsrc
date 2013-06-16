$NetBSD: patch-pan_general_log.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/general/log.cc.orig	2013-06-16 10:33:24.000000000 +0000
+++ pan/general/log.cc
@@ -68,7 +68,7 @@ Log :: add_entry(Entry& e, std::deque<En
   a.date = time(NULL);
   a.severity = e.severity;
   a.message = e.message;
-  a.messages = list;
+  *a.messages = list;
   fire_entry_added (a);
 }
 
