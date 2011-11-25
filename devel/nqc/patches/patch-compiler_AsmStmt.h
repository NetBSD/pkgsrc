$NetBSD: patch-compiler_AsmStmt.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/AsmStmt.h.orig	2011-11-25 20:15:13.000000000 +0000
+++ compiler/AsmStmt.h
@@ -25,7 +25,8 @@
 #include "RCX_Constants.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 
 class Field;
 class Expr;
