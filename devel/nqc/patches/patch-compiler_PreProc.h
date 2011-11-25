$NetBSD: patch-compiler_PreProc.h,v 1.1 2011/11/25 21:48:02 joerg Exp $

--- compiler/PreProc.h.orig	2011-11-25 20:13:54.000000000 +0000
+++ compiler/PreProc.h
@@ -33,7 +33,8 @@
 #include "Conditional.h"
 #endif
 
-#include <vector.h>
+#include <vector>
+using std::vector;
 
 class Symbol;
 class Expansion;
