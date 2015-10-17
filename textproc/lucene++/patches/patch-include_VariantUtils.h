$NetBSD: patch-include_VariantUtils.h,v 1.1 2015/10/17 03:02:47 ryoon Exp $

Fix compilation with Boost 1.58

https://github.com/luceneplusplus/LucenePlusPlus/commit/1987082cf9278a639d772b4f35a8ae2d34944177

--- include/VariantUtils.h.orig	2015-01-30 16:14:22.000000000 +0000
+++ include/VariantUtils.h
@@ -8,6 +8,7 @@
 #define VARIANTUTILS_H
 
 #include <boost/any.hpp>
+#include <boost/version.hpp>
 #include "Lucene.h"
 #include "MiscUtils.h"
 
@@ -22,7 +23,11 @@ public:
 
     template <typename TYPE, typename VAR>
     static TYPE get(VAR var) {
+#if BOOST_VERSION < 105800
         return var.type() == typeid(TYPE) ? boost::get<TYPE>(var) : TYPE();
+#else
+        return var.type() == typeid(TYPE) ? boost::relaxed_get<TYPE>(var) : TYPE();
+#endif
     }
 
     template <typename TYPE, typename VAR>
