$NetBSD: patch-core_src_ast_value__generator.cpp,v 1.1 2022/05/09 09:08:27 jperkin Exp $

Avoid ambiguous function calls.

--- core/src/ast/value_generator.cpp.orig	2020-09-11 00:52:41.000000000 +0000
+++ core/src/ast/value_generator.cpp
@@ -23,6 +23,7 @@
 #include "ast/seq_decl_plugin.h"
 #include <cmath>
 
+using std::sqrt;
 
 
 /*
