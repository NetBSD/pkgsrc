$NetBSD: patch-compiler_Expr.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/Expr.h.orig	2011-11-25 20:15:32.000000000 +0000
+++ compiler/Expr.h
@@ -33,7 +33,9 @@
 #include "LexLocation.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
+
 class Bytecode;
 class Mapping;
 class RCX_Target;
