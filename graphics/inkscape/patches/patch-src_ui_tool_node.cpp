$NetBSD: patch-src_ui_tool_node.cpp,v 1.1 2020/11/27 11:53:26 ryoon Exp $

* Fix error: field 'rel_error' has incomplete type 'std::atomic<double>'
  with boost-1.74.

--- src/ui/tool/node.cpp.orig	2020-09-07 09:02:10.000000000 +0000
+++ src/ui/tool/node.cpp
@@ -7,6 +7,7 @@
  * Released under GNU GPL v2+, read the file 'COPYING' for more information.
  */
 
+#include <atomic>
 #include <iostream>
 #include <stdexcept>
 #include <boost/utility.hpp>
