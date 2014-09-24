$NetBSD: patch-NumbTh.h,v 1.2 2014/09/24 12:39:28 jperkin Exp $

--- NumbTh.h.orig	2013-04-30 21:31:26.000000000 +0000
+++ NumbTh.h
@@ -32,13 +32,18 @@
 #include <NTL/mat_GF2E.h>
 #include <NTL/lzz_pXFactoring.h>
 #include <NTL/GF2XFactoring.h>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <unordered_map>
+#else
 #include <tr1/unordered_map>
+using std::tr1::unordered_map;
+#endif
 #include <string>
 NTL_CLIENT
 
 
 //! @typedef
-typedef tr1::unordered_map<string, const char *> argmap_t;
+typedef unordered_map<string, const char *> argmap_t;
 
 
 //! @brief Code for parsing command line arguments.
