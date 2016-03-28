$NetBSD: patch-tools_lldb-mi_MIUtilString.cpp,v 1.1 2016/03/28 13:13:55 kamil Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MIUtilString.cpp.orig	2016-02-21 02:08:07.000000000 +0000
+++ tools/lldb-mi/MIUtilString.cpp
@@ -159,7 +159,7 @@ CMIUtilString::FormatPriv(const CMIUtilS
 // Throws:  None.
 //--
 CMIUtilString
-CMIUtilString::Format(const CMIUtilString vFormating, ...)
+CMIUtilString::Format(const char* vFormating, ...)
 {
     va_list args;
     va_start(args, vFormating);
