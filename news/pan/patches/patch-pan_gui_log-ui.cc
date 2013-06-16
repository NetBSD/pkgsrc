$NetBSD: patch-pan_gui_log-ui.cc,v 1.1 2013/06/16 20:44:24 joerg Exp $

--- pan/gui/log-ui.cc.orig	2013-06-16 10:49:10.000000000 +0000
+++ pan/gui/log-ui.cc
@@ -57,11 +57,11 @@ namespace
                           COL_SEVERITY, (e.severity & Log::PAN_SEVERITY_ERROR),
                           COL_DATE, (unsigned long)e.date,
                           COL_MESSAGE, &e, -1);
-       if (!e.messages.empty())
+       if (!e.messages->empty())
        {
         GtkTreeIter child;
 
-        foreach_const (Log::entries_t, e.messages, lit)
+        foreach_const (Log::entries_t, *e.messages, lit)
         {
           gtk_tree_store_prepend (myStore, &child, &iter );
           gtk_tree_store_set (myStore, &child,
@@ -155,9 +155,9 @@ namespace
                           COL_SEVERITY, (it->severity & Log::PAN_SEVERITY_ERROR),
                           COL_DATE, (unsigned long)it->date,
                           COL_MESSAGE, &*it, -1);
-      if (!it->messages.empty())
+      if (!it->messages->empty())
       {
-        foreach_const (Log::entries_t, it->messages, lit)
+        foreach_const (Log::entries_t, *it->messages, lit)
         {
           gtk_tree_store_prepend (store, &child, &top );
           gtk_tree_store_set (store, &child,
