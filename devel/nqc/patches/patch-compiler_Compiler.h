$NetBSD: patch-compiler_Compiler.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/Compiler.h.orig	2011-11-25 20:14:07.000000000 +0000
+++ compiler/Compiler.h
@@ -17,7 +17,8 @@
 #ifndef __Compiler_h
 #define __Compiler_h
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 #include "RCX_Constants.h"
 #include "RCX_Target.h"
 
