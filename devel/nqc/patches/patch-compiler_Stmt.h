$NetBSD: patch-compiler_Stmt.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/Stmt.h.orig	2011-11-25 20:15:02.000000000 +0000
+++ compiler/Stmt.h
@@ -25,7 +25,8 @@
 #include "AutoFree.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 
 class Bytecode;
 class CheckState;
