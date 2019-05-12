$NetBSD: patch-src_editor_checkbox.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/checkbox.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/checkbox.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_EDITOR_CHECKBOX_HPP
 #define HEADER_PINGUS_EDITOR_CHECKBOX_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/gui/rect_component.hpp"
 
@@ -40,7 +40,7 @@ public:
   bool is_checked() const { return checked; }
   void on_primary_button_press(int x, int y);
 
-  boost::signal<void (bool)> on_change;
+  boost::signals2::signal<void (bool)> on_change;
  
 private:
   Checkbox (const Checkbox&);
