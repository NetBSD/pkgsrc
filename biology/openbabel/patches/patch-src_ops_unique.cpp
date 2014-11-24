$NetBSD: patch-src_ops_unique.cpp,v 1.2 2014/11/24 00:47:48 joerg Exp $

--- src/ops/unique.cpp.orig	2014-11-23 16:04:26.000000000 +0000
+++ src/ops/unique.cpp
@@ -21,10 +21,12 @@ GNU General Public License for more deta
 #include <openbabel/obconversion.h>
 #include <openbabel/descriptor.h>
 #include <openbabel/inchiformat.h>
-#ifdef _MSC_VER
+#include <cstddef>
+#if defined(_MSC_VER) || defined(_LIBCPP_VERSION) || __cplusplus>=201103L
   #include <unordered_map>
 #elif (__GNUC__ == 4 && __GNUC_MINOR__ >= 1 && !defined(__APPLE_CC__))
   #include <tr1/unordered_map>
+  using std::tr1::unordered_map;
 #else
   #ifdef USE_BOOST
     #include <boost/tr1/unordered_map.hpp>
@@ -35,9 +37,6 @@ GNU General Public License for more deta
 #endif
 
 using namespace std;
-#ifndef NO_UNORDERED_MAP
-using std::tr1::unordered_map;
-#endif
 namespace OpenBabel
 {
 
