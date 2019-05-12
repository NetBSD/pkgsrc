$NetBSD: patch-src_pingus_screens_option__menu.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/pingus/screens/option_menu.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/pingus/screens/option_menu.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_PINGUS_SCREENS_OPTION_MENU_HPP
 #define HEADER_PINGUS_PINGUS_SCREENS_OPTION_MENU_HPP
 
-#include <boost/signals.hpp>
+#include <boost/signals2.hpp>
 #include <map>
 #include <vector>
 
@@ -66,7 +66,7 @@ private:
   //Label* defaults_label;
   //CheckBox* defaults_box;
 
-  typedef std::vector<boost::signals::connection> Connections;
+  typedef std::vector<boost::signals2::connection> Connections;
   Connections connections;
 
   tinygettext::Language m_language;
