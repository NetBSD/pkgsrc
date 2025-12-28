$NetBSD: patch-include_lucene++_BitSet.h,v 1.1 2025/12/28 22:40:03 adam Exp $

Fix build with Boost 1.90.0.
https://github.com/void-linux/void-packages/blob/master/srcpkgs/Lucene%2B%2B/patches/boost-1.90.patch

--- include/lucene++/BitSet.h.orig	2024-02-18 18:18:26.000000000 +0000
+++ include/lucene++/BitSet.h
@@ -8,6 +8,7 @@
 #define BITSET_H
 
 #include <boost/dynamic_bitset.hpp>
+#include <boost/version.hpp>
 #include "LuceneObject.h"
 
 namespace Lucene {
@@ -24,7 +25,9 @@ protected:
     bitset_type bitSet;
 
 public:
+#if BOOST_VERSION < 109000
     const uint64_t* getBits();
+#endif
     void clear();
     void clear(uint32_t bitIndex);
     void fastClear(uint32_t bitIndex);
