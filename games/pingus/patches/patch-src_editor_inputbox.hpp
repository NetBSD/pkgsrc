$NetBSD: patch-src_editor_inputbox.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/inputbox.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/inputbox.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_EDITOR_INPUTBOX_HPP
 #define HEADER_PINGUS_EDITOR_INPUTBOX_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/gui/rect_component.hpp"
 
@@ -40,8 +40,8 @@ public:
 
   void update_layout() {}
 
-  boost::signal<void (const std::string&)> on_change;
-  boost::signal<void (const std::string&)> on_enter;
+  boost::signals2::signal<void (const std::string&)> on_change;
+  boost::signals2::signal<void (const std::string&)> on_enter;
 
 private:
   Inputbox (const Inputbox&);
