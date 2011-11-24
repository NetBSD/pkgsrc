$NetBSD: patch-src_RainbowTableDump.cpp,v 1.1 2011/11/24 13:35:52 joerg Exp $

--- src/RainbowTableDump.cpp.orig	2011-11-24 03:09:01.000000000 +0000
+++ src/RainbowTableDump.cpp
@@ -5,6 +5,7 @@
 */
 
 #include "ChainWalkContext.h"
+#include <stdlib.h>
 
 int main(int argc, char* argv[])
 {
