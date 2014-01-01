$NetBSD: patch-pan_general_log.h,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/general/log.h.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/general/log.h
@@ -24,6 +24,7 @@
 #include <set>
 #include <string>
 #include <deque>
+#include <pan/general/macros.h>
 
 namespace pan
 {
@@ -49,10 +50,11 @@ namespace pan
       struct Entry {
         time_t date;
         Severity severity;
-        std::deque<Entry> messages;
+        std::deque<Entry*> messages;
         std::string message;
         bool is_child;
-        Entry() : is_child(false) { }
+        Entry() : is_child(false), severity(PAN_SEVERITY_INFO), date(0) { }
+        virtual ~Entry () { foreach (std::deque<Entry*>, messages, it) delete *it; }
       };
 
       void add_entry(Entry& e, std::deque<Entry>& list);
@@ -66,6 +68,7 @@ namespace pan
       };
 
       typedef std::deque<Entry> entries_t;
+      typedef std::deque<Entry*> entries_p;
 
     public:
       void add (Severity, const char *);
