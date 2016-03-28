$NetBSD: patch-tools_lldb-mi_MICmnBase.cpp,v 1.1 2016/03/28 13:13:55 kamil Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MICmnBase.cpp.orig	2016-02-21 02:08:07.000000000 +0000
+++ tools/lldb-mi/MICmnBase.cpp
@@ -127,7 +127,7 @@ CMICmnBase::ClrErrorDescription() const
 // Throws:  None.
 //--
 void
-CMICmnBase::SetErrorDescriptionn(const CMIUtilString vFormat, ...) const
+CMICmnBase::SetErrorDescriptionn(const char *vFormat, ...) const
 {
     va_list args;
     va_start(args, vFormat);
