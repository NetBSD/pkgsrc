$NetBSD: patch-c_makeotf_lib_hotconv_FeatCtx.cpp,v 1.1 2026/02/09 16:49:07 ryoon Exp $

* Use header file from devel/antlr4-cpp-runtime.

--- c/makeotf/lib/hotconv/FeatCtx.cpp.orig	2026-02-04 12:24:20.553674613 +0000
+++ c/makeotf/lib/hotconv/FeatCtx.cpp
@@ -15,7 +15,7 @@
 #include "STAT.h"
 #include "name.h"
 
-#include "antlr4-runtime.h"
+#include <antlr4-runtime.h>
 #include <algorithm>
 #include "assert.h"
 #include <iostream>
