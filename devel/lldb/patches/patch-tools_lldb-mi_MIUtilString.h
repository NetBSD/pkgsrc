$NetBSD: patch-tools_lldb-mi_MIUtilString.h,v 1.1 2016/03/28 13:13:55 kamil Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MIUtilString.h.orig	2016-02-21 02:08:07.000000000 +0000
+++ tools/lldb-mi/MIUtilString.h
@@ -30,7 +30,7 @@ class CMIUtilString : public std::string
 
     // Static method:
   public:
-    static CMIUtilString Format(const CMIUtilString vFormating, ...);
+    static CMIUtilString Format(const char *vFormating, ...);
     static CMIUtilString FormatBinary(const MIuint64 vnDecimal);
     static CMIUtilString FormatValist(const CMIUtilString &vrFormating, va_list vArgs);
     static bool IsAllValidAlphaAndNumeric(const char *vpText);
