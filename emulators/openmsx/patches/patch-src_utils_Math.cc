$NetBSD: patch-src_utils_Math.cc,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/utils/Math.cc.orig	2013-09-20 13:39:09.000000000 +0000
+++ src/utils/Math.cc
@@ -6,6 +6,8 @@
 #include <emmintrin.h>
 #endif
 
+#include <cstdlib>
+
 namespace openmsx {
 
 #ifdef _MSC_VER
