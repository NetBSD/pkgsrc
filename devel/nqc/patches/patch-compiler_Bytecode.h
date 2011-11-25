$NetBSD: patch-compiler_Bytecode.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/Bytecode.h.orig	2011-11-25 20:15:22.000000000 +0000
+++ compiler/Bytecode.h
@@ -37,7 +37,8 @@
 #include "VarAllocator.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 
 class RCX_Cmd;
 
