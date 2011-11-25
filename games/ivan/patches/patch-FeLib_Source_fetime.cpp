$NetBSD: patch-FeLib_Source_fetime.cpp,v 1.1 2011/11/25 21:54:14 joerg Exp $

--- FeLib/Source/fetime.cpp.orig	2011-11-25 18:32:55.000000000 +0000
+++ FeLib/Source/fetime.cpp
@@ -14,6 +14,7 @@
    But it also should be rather easy to fix. */
 
 #include <ctime>
+#include <cstdlib>
 
 #include "fetime.h"
 #include "festring.h"
