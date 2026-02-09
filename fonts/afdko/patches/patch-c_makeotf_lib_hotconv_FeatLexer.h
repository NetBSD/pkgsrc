$NetBSD: patch-c_makeotf_lib_hotconv_FeatLexer.h,v 1.1 2026/02/09 16:49:07 ryoon Exp $

* Use header file from devel/antlr4-cpp-runtime.

--- c/makeotf/lib/hotconv/FeatLexer.h.orig	2026-02-04 12:23:31.092766375 +0000
+++ c/makeotf/lib/hotconv/FeatLexer.h
@@ -4,7 +4,7 @@
 #pragma once
 
 
-#include "antlr4-runtime.h"
+#include <antlr4-runtime.h>
 
 
 
