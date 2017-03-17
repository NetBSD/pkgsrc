$NetBSD: patch-tools_lldb-mi_MIUtilString.cpp,v 1.2 2017/03/17 22:38:17 adam Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MIUtilString.cpp.orig	2016-12-05 11:15:36.000000000 +0000
+++ tools/lldb-mi/MIUtilString.cpp
@@ -157,7 +157,7 @@ CMIUtilString CMIUtilString::FormatPriv(
 // Return:  CMIUtilString - Number of splits found in the string data.
 // Throws:  None.
 //--
-CMIUtilString CMIUtilString::Format(const CMIUtilString vFormating, ...) {
+CMIUtilString CMIUtilString::Format(const char *vFormating, ...) {
   va_list args;
   va_start(args, vFormating);
   CMIUtilString strResult = CMIUtilString::FormatPriv(vFormating, args);
