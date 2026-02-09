$NetBSD: patch-c_makeotf_lib_hotconv_FeatParser.h,v 1.1 2026/02/09 16:49:07 ryoon Exp $

* Use header file from devel/antlr4-cpp-runtime.

--- c/makeotf/lib/hotconv/FeatParser.h.orig	2026-02-04 12:23:44.047190675 +0000
+++ c/makeotf/lib/hotconv/FeatParser.h
@@ -4,7 +4,7 @@
 #pragma once
 
 
-#include "antlr4-runtime.h"
+#include <antlr4-runtime.h>
 
 
 
