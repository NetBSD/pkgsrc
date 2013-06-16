$NetBSD: patch-pan_usenet-utils_filter-info.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/usenet-utils/filter-info.cc.orig	2013-06-16 10:37:40.000000000 +0000
+++ pan/usenet-utils/filter-info.cc
@@ -38,7 +38,7 @@ FilterInfo :: clear ()
   _ge = 0;
   _header.clear ();
   _text.clear ();
-  _aggregates.clear ();
+  _aggregates->clear ();
   _negate = false;
   _needs_body = false;
 }
@@ -284,28 +284,28 @@ FilterInfo :: describe () const
   {
     ret = _("Any of these tests fail:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
+    foreach_const (aggregates_t, *_aggregates, it)
       ret += "   " + it->describe() + "\n";
   }
   else if (_type==AGGREGATE_AND)
   {
     ret = _("All of these tests pass:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
+    foreach_const (aggregates_t, *_aggregates, it)
       ret += "   " + it->describe() + "\n";
   }
   else if (_type==AGGREGATE_OR && _negate)
   {
     ret = _("None of these tests pass:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
+    foreach_const (aggregates_t, *_aggregates, it)
       ret += "   " + it->describe() + "\n";
   }
   else if (_type==AGGREGATE_OR)
   {
     ret = _("Any of these tests pass:");
     ret += "\n";
-    foreach_const (aggregates_t, _aggregates, it)
+    foreach_const (aggregates_t, *_aggregates, it)
       ret += "   " + it->describe() + "\n";
   }
 
