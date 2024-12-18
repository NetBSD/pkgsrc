$NetBSD: patch-src_script_C4AulParse.cpp,v 1.1 2024/12/18 10:41:25 wiz Exp $

Fix error: ‘numeric_limits’ is not a member of ‘std’

--- src/script/C4AulParse.cpp.orig	2024-12-18 10:37:34.023997067 +0000
+++ src/script/C4AulParse.cpp
@@ -26,6 +26,7 @@
 #define DEBUG_BYTECODE_DUMP 0
 #endif
 #include <iomanip>
+#include <limits>
 
 #define C4AUL_Include       "#include"
 #define C4AUL_Append        "#appendto"
