$NetBSD: patch-src_ui_tool_node.h,v 1.1 2014/01/11 17:48:52 wiz Exp $

--- src/ui/tool/node.h.orig	2012-02-14 03:22:17.000000000 +0000
+++ src/ui/tool/node.h
@@ -16,7 +16,9 @@
 #include <iosfwd>
 #include <stdexcept>
 #include <cstddef>
-#include <tr1/functional>
+
+#include <functional>
+
 #include <boost/utility.hpp>
 #include <boost/shared_ptr.hpp>
 #include <boost/optional.hpp>
@@ -32,12 +34,6 @@ template <typename> class NodeIterator;
 }
 }
 
-namespace std {
-namespace tr1 {
-template <typename N> struct hash< Inkscape::UI::NodeIterator<N> >;
-}
-}
-
 namespace Inkscape {
 namespace UI {
 
