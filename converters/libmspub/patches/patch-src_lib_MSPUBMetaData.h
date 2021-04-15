$NetBSD: patch-src_lib_MSPUBMetaData.h,v 1.1 2021/04/15 14:56:35 ryoon Exp $

* Fix build witn GCC 10 in NetBSD base.

--- src/lib/MSPUBMetaData.h.orig	2018-02-28 11:54:49.000000000 +0000
+++ src/lib/MSPUBMetaData.h
@@ -13,6 +13,7 @@
 #include <map>
 #include <utility>
 #include <vector>
+#include <cstdint>
 
 #include <librevenge/librevenge.h>
 
