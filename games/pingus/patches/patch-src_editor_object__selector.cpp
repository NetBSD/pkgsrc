$NetBSD: patch-src_editor_object__selector.cpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/object_selector.cpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/object_selector.cpp
@@ -16,7 +16,7 @@
 
 #include "editor/object_selector.hpp"
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "editor/generic_level_obj.hpp"
 #include "editor/gui_style.hpp"
@@ -47,7 +47,7 @@ private:
   std::string tooltip;
   
 public:
-  boost::signal<void()> on_click;
+  boost::signals2::signal<void()> on_click;
 
 public:
   ObjectSelectorButton(ObjectSelectorList* object_list_,
