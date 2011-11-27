$NetBSD: patch-cmn_world.cpp,v 1.1 2011/11/27 19:43:33 joerg Exp $

--- cmn/world.cpp.orig	2011-11-27 02:22:11.000000000 +0000
+++ cmn/world.cpp
@@ -35,7 +35,7 @@
 #endif
 
 // Include Files.
-#include <iostream.h>
+#include <iostream>
 
 #include "utils.h"
 #include "coord.h"
