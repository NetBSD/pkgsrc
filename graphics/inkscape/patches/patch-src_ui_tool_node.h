$NetBSD: patch-src_ui_tool_node.h,v 1.2 2014/07/29 07:03:27 adam Exp $

--- src/ui/tool/node.h.orig	2014-07-29 04:46:51.000000000 +0000
+++ src/ui/tool/node.h
@@ -17,11 +17,7 @@
 #include <stdexcept>
 #include <cstddef>
 
-#if __cplusplus >= 201103L
 #include <functional>
-#else
-#include <tr1/functional>
-#endif
 
 #include <boost/utility.hpp>
 #include <boost/shared_ptr.hpp>
@@ -38,13 +34,6 @@ template <typename> class NodeIterator;
 }
 }
 
-#if __cplusplus < 201103L
-namespace std {
-namespace tr1 {
-template <typename N> struct hash< Inkscape::UI::NodeIterator<N> >;
-}
-}
-#endif
 
 namespace Inkscape {
 namespace UI {
