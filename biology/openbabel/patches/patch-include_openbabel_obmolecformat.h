$NetBSD: patch-include_openbabel_obmolecformat.h,v 1.1 2013/05/06 14:22:42 joerg Exp $

--- include/openbabel/obmolecformat.h.orig	2013-05-05 20:25:43.000000000 +0000
+++ include/openbabel/obmolecformat.h
@@ -23,7 +23,10 @@ GNU General Public License for more deta
   #include <hash_map>
 #endif
 
-#if __GNUC__ == 4 && __GNUC_MINOR__ >= 1
+#include <ciso646>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <unordered_map>
+#elif __GNUC__ == 4 && __GNUC_MINOR__ >= 1
   #include <tr1/unordered_map>
 #elif defined(USE_BOOST)
   #include <boost/tr1/unordered_map.hpp>
@@ -141,6 +144,8 @@ public:
 
 #ifdef _MSC_VER
   typedef stdext::hash_map<std::string, unsigned> NameIndexType;
+#elif defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  typedef std::unordered_map<std::string, unsigned> NameIndexType;
 #elif (__GNUC__ == 4 && __GNUC_MINOR__ >= 1 && !defined(__APPLE_CC__)) || defined (USE_BOOST)
   typedef std::tr1::unordered_map<std::string, unsigned> NameIndexType;
 #else
