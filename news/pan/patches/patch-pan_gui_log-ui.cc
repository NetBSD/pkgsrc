$NetBSD: patch-pan_gui_log-ui.cc,v 1.3 2014/01/01 12:10:00 wiz Exp $

--- pan/gui/log-ui.cc.orig	2012-06-29 22:24:54.000000000 +0000
+++ pan/gui/log-ui.cc
@@ -61,13 +61,14 @@ namespace
        {
         GtkTreeIter child;
 
-        foreach_const (Log::entries_t, e.messages, lit)
+        foreach_const (Log::entries_p, e.messages, lit)
         {
+          Log::Entry entry(**lit);
           gtk_tree_store_prepend (myStore, &child, &iter );
           gtk_tree_store_set (myStore, &child,
                           COL_HIDDEN, "",
-                          COL_SEVERITY, (lit->severity & Log::PAN_SEVERITY_ERROR),
-                          COL_DATE, (unsigned long)lit->date,
+                          COL_SEVERITY, (entry.severity & Log::PAN_SEVERITY_ERROR),
+                          COL_DATE, (unsigned long)entry.date,
                           COL_MESSAGE, &*lit, -1);
         }
       }
@@ -157,13 +158,14 @@ namespace
                           COL_MESSAGE, &*it, -1);
       if (!it->messages.empty())
       {
-        foreach_const (Log::entries_t, it->messages, lit)
+        foreach_const (Log::entries_p, it->messages, lit)
         {
+          Log::Entry entry (**lit);
           gtk_tree_store_prepend (store, &child, &top );
           gtk_tree_store_set (store, &child,
                           COL_HIDDEN, "",
-                          COL_SEVERITY, (lit->severity & Log::PAN_SEVERITY_ERROR),
-                          COL_DATE, (unsigned long)lit->date,
+                          COL_SEVERITY, (entry.severity & Log::PAN_SEVERITY_ERROR),
+                          COL_DATE, (unsigned long)entry.date,
                           COL_MESSAGE, &*lit, -1);
         }
       }
