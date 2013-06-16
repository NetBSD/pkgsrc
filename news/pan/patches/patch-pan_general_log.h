$NetBSD: patch-pan_general_log.h,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/general/log.h.orig	2013-06-16 10:31:39.000000000 +0000
+++ pan/general/log.h
@@ -49,10 +49,11 @@ namespace pan
       struct Entry {
         time_t date;
         Severity severity;
-        std::deque<Entry> messages;
+        std::deque<Entry> *messages;
         std::string message;
         bool is_child;
-        Entry() : is_child(false) { }
+        Entry() : is_child(false), messages(new(std::deque<Entry>)) { }
+        ~Entry() { delete messages;}
       };
 
       void add_entry(Entry& e, std::deque<Entry>& list);
