$NetBSD: patch-src_editor_viewport.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/editor/viewport.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/editor/viewport.hpp
@@ -18,7 +18,7 @@
 #ifndef HEADER_PINGUS_EDITOR_VIEWPORT_HPP
 #define HEADER_PINGUS_EDITOR_VIEWPORT_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 #include <set>
 
 #include "editor/selection.hpp"
@@ -148,7 +148,7 @@ public:
 
   void clear_selection();
 
-  boost::signal<void (const Selection&)> selection_changed;
+  boost::signals2::signal<void (const Selection&)> selection_changed;
 private:
   Viewport();
   Viewport (const Viewport&);
