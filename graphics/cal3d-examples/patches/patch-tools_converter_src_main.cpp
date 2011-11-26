$NetBSD: patch-tools_converter_src_main.cpp,v 1.1 2011/11/26 17:12:24 joerg Exp $

--- tools/converter/src/main.cpp.orig	2011-11-26 15:10:20.000000000 +0000
+++ tools/converter/src/main.cpp
@@ -10,6 +10,9 @@
 
 #include "cal3d/cal3d.h"
 
+#include <cstring>
+#include <strings.h>
+
 #define SKELETON 0
 #define MESH 1
 #define ANIMATION 2
