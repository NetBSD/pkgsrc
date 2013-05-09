$NetBSD: patch-include_pugixml.hpp,v 1.1 2013/05/09 13:58:54 joerg Exp $

--- include/pugixml.hpp.orig	2013-02-21 17:10:46.000000000 +0000
+++ include/pugixml.hpp
@@ -18,6 +18,11 @@
 #include "version.h"
 
 #ifndef PUGIXML_NO_STL
+#include <iterator>
+#include <string>
+#include <istream>
+#include <ostream>
+#if 0
 namespace std
 {
 	struct bidirectional_iterator_tag;
@@ -45,6 +50,7 @@ namespace std
 #endif
 }
 #endif
+#endif
 
 // Macro for deprecated features
 #ifndef PUGIXML_DEPRECATED
