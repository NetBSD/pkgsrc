$NetBSD: patch-src_gtkglue.c,v 1.1 2015/12/15 12:20:12 wiz Exp $

SANE_CAP_ALWAYS_SETTABLE was removed from the sane-backends API.

--- src/gtkglue.c.orig	2005-04-16 13:12:07.000000000 +0000
+++ src/gtkglue.c
@@ -1475,9 +1475,6 @@ gsg_set_sensitivity (GSGDialog * dialog,
       if (!SANE_OPTION_IS_ACTIVE (opt->cap)
 	  || opt->type == SANE_TYPE_GROUP || !dialog->element[i].widget)
 	continue;
-
-      if (!(opt->cap & SANE_CAP_ALWAYS_SETTABLE))
-	gtk_widget_set_sensitive (dialog->element[i].widget, sensitive);
     }
 }
 
