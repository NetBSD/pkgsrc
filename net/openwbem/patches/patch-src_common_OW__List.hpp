$NetBSD: patch-src_common_OW__List.hpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/common/OW_List.hpp.orig	2013-03-25 15:33:34.000000000 +0000
+++ src/common/OW_List.hpp
@@ -36,12 +36,10 @@
 #ifndef OW_LIST_HPP_INCLUDE_GUARD_
 #define OW_LIST_HPP_INCLUDE_GUARD_
 #include "OW_config.h"
-#include "OW_COWReference.hpp"
 #include <list>
 
 namespace OW_NAMESPACE
 {
-
 // forward declarations are necessary for template friends.
 template<class T> class List;
 
@@ -51,7 +49,17 @@ inline bool operator==(const List<T>& x,
 template <class T>
 inline bool operator<(const List<T>& x, const List<T>& y);
 
-	
+template <class T>
+std::list<T>* COWReferenceClone(std::list<T>* obj)
+{
+	return new std::list<T>(*obj);
+}
+}
+
+#include "OW_COWReference.hpp"
+
+namespace OW_NAMESPACE
+{
 /**
  * This class is a wrapper around std::list<> and adds COW capabilities.
  */
@@ -289,11 +297,6 @@ inline void swap(List<T>& x, List<T>& y)
 {
 	x.swap(y);
 }
-template <class T>
-std::list<T>* COWReferenceClone(std::list<T>* obj)
-{
-	return new std::list<T>(*obj);
-}
 
 } // end namespace OW_NAMESPACE
 
