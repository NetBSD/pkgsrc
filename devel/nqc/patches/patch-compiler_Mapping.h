$NetBSD: patch-compiler_Mapping.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/Mapping.h.orig	2011-11-25 20:17:32.000000000 +0000
+++ compiler/Mapping.h
@@ -22,7 +22,8 @@
 #include "Variable.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 
 class Expr;
 
