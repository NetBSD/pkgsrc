$NetBSD: patch-src_RainbowCrack.cpp,v 1.1 2011/11/24 13:35:52 joerg Exp $

--- src/RainbowCrack.cpp.orig	2011-11-24 03:10:04.000000000 +0000
+++ src/RainbowCrack.cpp
@@ -9,6 +9,7 @@
 #endif
 
 #include "CrackEngine.h"
+#include <string.h>
 
 #ifdef _WIN32
 	#include <io.h>
