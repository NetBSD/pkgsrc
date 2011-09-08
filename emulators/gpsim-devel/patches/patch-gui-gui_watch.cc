$NetBSD: patch-gui-gui_watch.cc,v 1.1 2011/09/08 00:12:00 joerg Exp $

--- gui/gui_watch.cc.orig	2011-09-07 13:34:41.000000000 +0000
+++ gui/gui_watch.cc
@@ -478,7 +478,7 @@ void Watch_Window::UpdateWatch(WatchEntr
     strcpy(str, "?");
   }
   else {
-    sprintf(str,"%d", rvNewValue);
+    sprintf(str,"%d", new_value);
   }
   gtk_clist_set_text(GTK_CLIST(watch_clist), row, DECIMALCOL, str);
 
