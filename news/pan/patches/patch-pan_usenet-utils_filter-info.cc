$NetBSD: patch-pan_usenet-utils_filter-info.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/usenet-utils/filter-info.cc.orig	2013-12-21 12:32:25.000000000 +0000
+++ pan/usenet-utils/filter-info.cc
@@ -38,6 +38,8 @@ FilterInfo :: clear ()
   _ge = 0;
   _header.clear ();
   _text.clear ();
+  foreach (aggregatesp_t, _aggregates, it)
+    delete *it;
   _aggregates.clear ();
   _negate = false;
   _needs_body = false;
@@ -284,29 +286,29 @@ FilterInfo :: describe () const
   {
     ret = _("Any of these tests fail:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
-      ret += "   " + it->describe() + "\n";
+    foreach_const (aggregatesp_t, _aggregates, it)
+      ret += "   " + (*it)->describe() + "\n";
   }
   else if (_type==AGGREGATE_AND)
   {
     ret = _("All of these tests pass:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
-      ret += "   " + it->describe() + "\n";
+    foreach_const (aggregatesp_t, _aggregates, it)
+      ret += "   " + (*it)->describe() + "\n";
   }
   else if (_type==AGGREGATE_OR && _negate)
   {
     ret = _("None of these tests pass:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
-      ret += "   " + it->describe() + "\n";
+    foreach_const (aggregatesp_t, _aggregates, it)
+      ret += "   " + (*it)->describe() + "\n";
   }
   else if (_type==AGGREGATE_OR)
   {
     ret = _("Any of these tests pass:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
-      ret += "   " + it->describe() + "\n";
+    foreach_const (aggregatesp_t, _aggregates, it)
+      ret += "   " + (*it)->describe() + "\n";
   }
 
   return ret;
