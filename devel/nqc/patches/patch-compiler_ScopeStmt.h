$NetBSD: patch-compiler_ScopeStmt.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/ScopeStmt.h.orig	2011-11-25 20:17:18.000000000 +0000
+++ compiler/ScopeStmt.h
@@ -21,8 +21,6 @@
 #include "Stmt.h"
 #endif
 
-#include <vector.h>
-
 class ScopeStmt : public ChainStmt
 {
 public:
