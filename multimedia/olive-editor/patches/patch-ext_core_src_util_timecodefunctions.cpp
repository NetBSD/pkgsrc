$NetBSD: patch-ext_core_src_util_timecodefunctions.cpp,v 1.1 2023/10/15 19:57:54 ryoon Exp $

* for std:ceil etc.

--- ext/core/src/util/timecodefunctions.cpp.orig	2023-02-17 02:04:25.000000000 +0000
+++ ext/core/src/util/timecodefunctions.cpp
@@ -18,6 +18,7 @@
 
 ***/
 
+#include <cmath>
 #include "util/timecodefunctions.h"
 
 extern "C" {
