$NetBSD: patch-opal_opal.cpp,v 1.1 2023/08/29 21:49:57 bacon Exp $

# Fix compile error on Darwin 21.6.0

--- opal/opal.cpp.orig	2023-08-29 21:20:11.000000000 +0000
+++ opal/opal.cpp
@@ -5,10 +5,8 @@
 #include <limits>
 #include <vector>
 
-extern "C" {
 #define SIMDE_ENABLE_NATIVE_ALIASES
 #include <simde_avx2.h> // AVX2 and lower
-}
 
 #include "opal.h"
 
