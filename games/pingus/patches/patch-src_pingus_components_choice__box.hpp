$NetBSD: patch-src_pingus_components_choice__box.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/pingus/components/choice_box.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/pingus/components/choice_box.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_PINGUS_COMPONENTS_CHOICE_BOX_HPP
 #define HEADER_PINGUS_PINGUS_COMPONENTS_CHOICE_BOX_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/gui/rect_component.hpp"
 
@@ -36,7 +36,7 @@ public:
   void add_choice(const std::string& str);
   void set_current_choice(int choice);
   
-  boost::signal<void (std::string)> on_change;
+  boost::signals2::signal<void (std::string)> on_change;
   
 private:
   ChoiceBox (const ChoiceBox&);
