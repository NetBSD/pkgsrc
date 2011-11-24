$NetBSD: patch-src_gengine_StringTool.cpp,v 1.1 2011/11/24 14:08:48 joerg Exp $

--- src/gengine/StringTool.cpp.orig	2011-11-24 00:51:28.000000000 +0000
+++ src/gengine/StringTool.cpp
@@ -8,6 +8,7 @@
  */
 #include "StringTool.h"
 
+#include <stdlib.h>
 #include <sstream>
 
 //-----------------------------------------------------------------
