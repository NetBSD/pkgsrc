$NetBSD: patch-src_ui_widget_registered-widget.h,v 1.1 2012/11/16 00:54:05 joerg Exp $

--- src/ui/widget/registered-widget.h.orig	2012-11-15 16:20:03.000000000 +0000
+++ src/ui/widget/registered-widget.h
@@ -62,7 +62,7 @@ public:
     bool is_updating() {if (_wr) return _wr->isUpdating(); else return false;}
 
     // provide automatic 'upcast' for ease of use. (do it 'dynamic_cast' instead of 'static' because who knows what W is)
-    operator const Gtk::Widget () { return dynamic_cast<Gtk::Widget*>(this); }
+    operator const Gtk::Widget *() { return dynamic_cast<Gtk::Widget*>(this); }
 
 protected:
     RegisteredWidget() : W() { construct(); }
