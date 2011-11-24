$NetBSD: patch-src_RainbowTableGenerate.cpp,v 1.1 2011/11/24 13:35:52 joerg Exp $

--- src/RainbowTableGenerate.cpp.orig	2011-11-24 03:07:52.000000000 +0000
+++ src/RainbowTableGenerate.cpp
@@ -13,6 +13,8 @@
 #else
 	#include <unistd.h>
 #endif
+#include <stdlib.h>
+#include <string.h>
 #include <time.h>
 
 #include "ChainWalkContext.h"
