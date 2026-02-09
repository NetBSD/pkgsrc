$NetBSD: patch-c_makeotf_lib_hotconv_FeatParserVisitor.h,v 1.1 2026/02/09 16:49:07 ryoon Exp $

* Use header file from devel/antlr4-cpp-runtime.

--- c/makeotf/lib/hotconv/FeatParserVisitor.h.orig	2026-02-04 12:23:19.255239647 +0000
+++ c/makeotf/lib/hotconv/FeatParserVisitor.h
@@ -4,7 +4,7 @@
 #pragma once
 
 
-#include "antlr4-runtime.h"
+#include <antlr4-runtime.h>
 #include "FeatParser.h"
 
 
