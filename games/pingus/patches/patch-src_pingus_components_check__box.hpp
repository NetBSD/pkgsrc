$NetBSD: patch-src_pingus_components_check__box.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/pingus/components/check_box.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/pingus/components/check_box.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_PINGUS_COMPONENTS_CHECK_BOX_HPP
 #define HEADER_PINGUS_PINGUS_COMPONENTS_CHECK_BOX_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "engine/display/sprite.hpp"
 #include "engine/gui/rect_component.hpp"
@@ -39,7 +39,7 @@ public:
 
   void set_state(bool v, bool send_signal);
 
-  boost::signal<void (bool)> on_change;
+  boost::signals2::signal<void (bool)> on_change;
 
 private:
   CheckBox (const CheckBox&);
