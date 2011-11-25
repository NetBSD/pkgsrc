$NetBSD: patch-compiler_SwitchStmt.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/SwitchStmt.h.orig	2011-11-25 20:16:57.000000000 +0000
+++ compiler/SwitchStmt.h
@@ -25,8 +25,6 @@
 #include "Expr.h"
 #endif
 
-#include <vector.h>
-
 class SwitchStmt : public ChainStmt
 {
 public:
