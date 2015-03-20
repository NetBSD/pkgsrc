$NetBSD: patch-tryton_gui_window_view__form_view_form__gtk_multiselection.py,v 1.2 2015/03/20 00:58:38 tnn Exp $

Fixes python 2.6 support. Patch can go away when python26 does.

--- tryton/common/treeviewcontrol.py.orig	2015-02-09 23:43:55.000000000 +0000
+++ tryton/common/treeviewcontrol.py
@@ -3,11 +3,11 @@
 import gtk
 import gobject
 
-MOVEMENT_KEYS = {gtk.keysyms.Up, gtk.keysyms.Down, gtk.keysyms.space,
+MOVEMENT_KEYS = set((gtk.keysyms.Up, gtk.keysyms.Down, gtk.keysyms.space,
     gtk.keysyms.Left, gtk.keysyms.KP_Left,
     gtk.keysyms.Right, gtk.keysyms.KP_Right,
     gtk.keysyms.Home, gtk.keysyms.KP_Home,
-    gtk.keysyms.End, gtk.keysyms.KP_End}
+    gtk.keysyms.End, gtk.keysyms.KP_End))
 
 __all__ = ['TreeViewControl']
 
