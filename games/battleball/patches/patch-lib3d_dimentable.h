$NetBSD: patch-lib3d_dimentable.h,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/dimentable.h.orig	2011-11-25 15:14:16.000000000 +0000
+++ lib3d/dimentable.h
@@ -7,9 +7,10 @@
 #define DIMENTABLE_h
 
 
-#include <list.h>  // STL
+#include <list>  // STL
 #include "dimension.h"
 
+using namespace std;
 
 /*=========================================================================*/
 struct dimenTable {
