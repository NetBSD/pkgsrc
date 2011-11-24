$NetBSD: patch-src_ChainWalkContext.cpp,v 1.1 2011/11/24 13:35:52 joerg Exp $

--- src/ChainWalkContext.cpp.orig	2011-11-24 03:08:16.000000000 +0000
+++ src/ChainWalkContext.cpp
@@ -10,6 +10,7 @@
 
 #include "ChainWalkContext.h"
 
+#include <string.h>
 #include <ctype.h>
 #include <openssl/rand.h>
 #ifdef _WIN32
