$NetBSD: patch-tryton_gui_window_view__form_view_form__gtk_multiselection.py,v 1.1 2014/06/06 12:48:00 joerg Exp $

--- tryton/gui/window/view_form/view/form_gtk/multiselection.py.orig	2014-06-06 12:01:50.000000000 +0000
+++ tryton/gui/window/view_form/view/form_gtk/multiselection.py
@@ -6,11 +6,11 @@ import gobject
 from .interface import WidgetInterface
 from tryton.common.selection import SelectionMixin
 
-MOVEMENT_KEYS = {gtk.keysyms.Up, gtk.keysyms.Down, gtk.keysyms.space,
+MOVEMENT_KEYS = set((gtk.keysyms.Up, gtk.keysyms.Down, gtk.keysyms.space,
     gtk.keysyms.Left, gtk.keysyms.KP_Left,
     gtk.keysyms.Right, gtk.keysyms.KP_Right,
     gtk.keysyms.Home, gtk.keysyms.KP_Home,
-    gtk.keysyms.End, gtk.keysyms.KP_End}
+    gtk.keysyms.End, gtk.keysyms.KP_End))
 
 
 class MultiSelection(WidgetInterface, SelectionMixin):
