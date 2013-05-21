$NetBSD: patch-IndexMap.h,v 1.1 2013/05/21 16:37:46 joerg Exp $

--- IndexMap.h.orig	2013-05-21 14:44:35.000000000 +0000
+++ IndexMap.h
@@ -21,9 +21,14 @@
  **/
 
 #include "IndexSet.h"
-#include <tr1/unordered_map>
 #include <iostream>
 #include <cassert>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <unordered_map>
+#else
+#include <tr1/unordered_map>
+using std::tr1::unordered_map;
+#endif
 #include "cloned_ptr.h"
 
 using namespace std;
@@ -46,7 +51,7 @@ public:
 //! flexible manner.
 template < class T > class IndexMap {
 
-  tr1::unordered_map<long, T> map;
+  unordered_map<long, T> map;
   IndexSet indexSet;
   cloned_ptr< IndexMapInit<T> > init;
 
@@ -78,8 +83,8 @@ public:
     assert(indexSet.contains(j)); 
     // unordered_map does not support a const [] operator,
     // so we have to artificially strip away the const-ness here
-    tr1::unordered_map<long, T> & map1 = 
-      const_cast< tr1::unordered_map<long, T> & > (map);
+    unordered_map<long, T> & map1 = 
+      const_cast< unordered_map<long, T> & > (map);
     return map1[j];
   }
 
