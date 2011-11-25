$NetBSD: patch-compiler_CallStmt.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/CallStmt.h.orig	2011-11-25 20:16:35.000000000 +0000
+++ compiler/CallStmt.h
@@ -25,8 +25,6 @@
 #include "parser.h"
 #endif
 
-#include <vector.h>
-
 class Symbol;
 class Expr;
 
