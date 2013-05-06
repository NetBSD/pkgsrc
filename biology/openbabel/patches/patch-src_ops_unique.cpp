$NetBSD: patch-src_ops_unique.cpp,v 1.1 2013/05/06 14:22:43 joerg Exp $

--- src/ops/unique.cpp.orig	2013-05-05 20:34:38.000000000 +0000
+++ src/ops/unique.cpp
@@ -23,6 +23,9 @@ GNU General Public License for more deta
 #include <openbabel/inchiformat.h>
 #ifdef _MSC_VER
   #include <unordered_map>
+#elif defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+# include <unordered_map>
+using std::unordered_map;
 #elif (__GNUC__ == 4 && __GNUC_MINOR__ >= 1 && !defined(__APPLE_CC__))
   #include <tr1/unordered_map>
 #else
@@ -35,7 +38,7 @@ GNU General Public License for more deta
 #endif
 
 using namespace std;
-#ifndef NO_UNORDERED_MAP
+#if !defined(NO_UNORDERED_MAP) && !defined(_LIBCPP_VERSION) && __cplusplus < 201103L
 using std::tr1::unordered_map;
 #endif
 namespace OpenBabel
