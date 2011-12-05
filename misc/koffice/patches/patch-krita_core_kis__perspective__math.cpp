$NetBSD: patch-krita_core_kis__perspective__math.cpp,v 1.1 2011/12/05 22:52:24 joerg Exp $

--- krita/core/kis_perspective_math.cpp.orig	2011-12-05 18:29:04.000000000 +0000
+++ krita/core/kis_perspective_math.cpp
@@ -24,13 +24,15 @@
 
 #if 1
 
-#include <iostream.h>
+#include <iostream>
 #include <stdlib.h>
 #include <math.h>
 //#define NDEBUG // uncomment to remove checking of assert()
 #include <assert.h>
 #define DEFAULT_ALLOC 2
 
+using namespace std;
+
 namespace math { // TODO: use eigen
 
 template <class ElType> class matrix;
