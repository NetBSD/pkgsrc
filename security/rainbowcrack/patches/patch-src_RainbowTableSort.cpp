$NetBSD: patch-src_RainbowTableSort.cpp,v 1.1 2011/11/24 13:35:52 joerg Exp $

--- src/RainbowTableSort.cpp.orig	2011-11-24 03:09:27.000000000 +0000
+++ src/RainbowTableSort.cpp
@@ -5,6 +5,7 @@
 */
 
 #include "Public.h"
+#include <stdlib.h>
 
 #define ASSUMED_MIN_MEMORY 32 * 1024 * 1024
 
