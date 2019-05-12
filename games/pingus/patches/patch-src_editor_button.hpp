$NetBSD: patch-src_editor_button.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/button.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/button.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_EDITOR_BUTTON_HPP
 #define HEADER_PINGUS_EDITOR_BUTTON_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/gui/rect_component.hpp"
 
@@ -48,7 +48,7 @@ public:
   void enable()  { enabled = true; }
   void disable() { enabled = false; }
 
-  boost::signal<void()> on_click;
+  boost::signals2::signal<void()> on_click;
 
 private:
   Button (const Button&);
