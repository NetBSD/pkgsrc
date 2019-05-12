$NetBSD: patch-src_editor_combobox.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/combobox.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/combobox.hpp
@@ -18,7 +18,7 @@
 #ifndef HEADER_PINGUS_EDITOR_COMBOBOX_HPP
 #define HEADER_PINGUS_EDITOR_COMBOBOX_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/display/sprite.hpp"
 #include "engine/gui/rect_component.hpp"
@@ -88,7 +88,7 @@ public:
   
   void update_layout() {}
   
-  boost::signal<void (const ComboItem&)> on_select;
+  boost::signals2::signal<void (const ComboItem&)> on_select;
 
 private:
   Combobox();
