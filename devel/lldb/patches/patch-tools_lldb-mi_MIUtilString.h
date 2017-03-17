$NetBSD: patch-tools_lldb-mi_MIUtilString.h,v 1.2 2017/03/17 22:38:17 adam Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MIUtilString.h.orig	2016-09-06 20:57:50.000000000 +0000
+++ tools/lldb-mi/MIUtilString.h
@@ -30,7 +30,7 @@ public:
 
   // Static method:
 public:
-  static CMIUtilString Format(const CMIUtilString vFormating, ...);
+  static CMIUtilString Format(const char *vFormating, ...);
   static CMIUtilString FormatBinary(const MIuint64 vnDecimal);
   static CMIUtilString FormatValist(const CMIUtilString &vrFormating,
                                     va_list vArgs);
