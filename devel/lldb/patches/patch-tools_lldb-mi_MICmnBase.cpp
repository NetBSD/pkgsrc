$NetBSD: patch-tools_lldb-mi_MICmnBase.cpp,v 1.2 2017/03/17 22:38:17 adam Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MICmnBase.cpp.orig	2016-09-06 20:57:50.000000000 +0000
+++ tools/lldb-mi/MICmnBase.cpp
@@ -122,7 +122,7 @@ void CMICmnBase::ClrErrorDescription() c
 // Return:  None.
 // Throws:  None.
 //--
-void CMICmnBase::SetErrorDescriptionn(const CMIUtilString vFormat, ...) const {
+void CMICmnBase::SetErrorDescriptionn(const char *vFormat, ...) const {
   va_list args;
   va_start(args, vFormat);
   CMIUtilString strResult = CMIUtilString::FormatValist(vFormat, args);
