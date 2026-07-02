$NetBSD: patch-baseTypes_simpleExecutable.cpp,v 1.1 2026/07/02 19:34:02 alnsn Exp $

Don't assume that the root directory is named "symfpu".

--- baseTypes/simpleExecutable.cpp.orig	2026-07-01 22:11:25.492879747 +0000
+++ baseTypes/simpleExecutable.cpp
@@ -12,7 +12,7 @@
 */
 
 
-#include "symfpu/baseTypes/simpleExecutable.h"
+#include "baseTypes/simpleExecutable.h"
 
 #include <assert.h>
 #include <math.h>
