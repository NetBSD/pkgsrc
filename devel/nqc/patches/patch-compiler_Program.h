$NetBSD: patch-compiler_Program.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/Program.h.orig	2011-11-25 20:13:40.000000000 +0000
+++ compiler/Program.h
@@ -41,7 +41,7 @@
 #include "VarAllocator.h"
 #endif
 
-#include <vector.h>
+#include <vector>
 
 class Fragment;
 class FunctionDef;
