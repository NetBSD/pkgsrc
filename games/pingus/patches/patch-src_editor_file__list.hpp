$NetBSD: patch-src_editor_file__list.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/file_list.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/file_list.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_EDITOR_FILE_LIST_HPP
 #define HEADER_PINGUS_EDITOR_FILE_LIST_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/display/sprite.hpp"
 #include "engine/gui/rect_component.hpp"
@@ -61,7 +61,7 @@ public:
   bool has_more_next_pages();
   bool has_more_prev_pages();
 
-  boost::signal<void (const System::DirectoryEntry&)> on_click;
+  boost::signals2::signal<void (const System::DirectoryEntry&)> on_click;
 
 private:
   int items_per_page();
