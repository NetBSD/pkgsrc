$NetBSD: patch-include_pugixml.hpp,v 1.2 2013/10/12 22:13:44 ryoon Exp $

--- include/pugixml.hpp.orig	2013-09-30 17:25:21.000000000 +0000
+++ include/pugixml.hpp
@@ -23,6 +23,11 @@
 
 
 #ifndef PUGIXML_NO_STL
+#include <iterator>
+#include <string>
+#include <istream>
+#include <ostream>
+#if 0
 namespace std
 {
 	struct bidirectional_iterator_tag;
@@ -50,6 +55,7 @@ namespace std
 #endif
 }
 #endif
+#endif
 
 // Macro for deprecated features
 #ifndef PUGIXML_DEPRECATED
