$NetBSD: patch-FeLib_Source_festring.cpp,v 1.1 2011/11/25 21:54:14 joerg Exp $

--- FeLib/Source/festring.cpp.orig	2011-11-25 18:33:17.000000000 +0000
+++ FeLib/Source/festring.cpp
@@ -11,6 +11,7 @@
  */
 
 #include <cctype>
+#include <cstdlib>
 
 #include "festring.h"
 #include "allocate.h"
