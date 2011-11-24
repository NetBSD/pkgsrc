$NetBSD: patch-src_ChainWalkSet.cpp,v 1.1 2011/11/24 13:35:52 joerg Exp $

--- src/ChainWalkSet.cpp.orig	2011-11-24 03:09:44.000000000 +0000
+++ src/ChainWalkSet.cpp
@@ -8,6 +8,7 @@
 	#pragma warning(disable : 4786)
 #endif
 
+#include <string.h>
 #include "ChainWalkSet.h"
 
 CChainWalkSet::CChainWalkSet()
