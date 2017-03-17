$NetBSD: patch-tools_lldb-mi_MICmnBase.h,v 1.2 2017/03/17 22:38:17 adam Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MICmnBase.h.orig	2016-09-06 20:57:50.000000000 +0000
+++ tools/lldb-mi/MICmnBase.h
@@ -28,7 +28,7 @@ public:
   bool HaveErrorDescription() const;
   const CMIUtilString &GetErrorDescription() const;
   void SetErrorDescription(const CMIUtilString &vrTxt) const;
-  void SetErrorDescriptionn(const CMIUtilString vFormat, ...) const;
+  void SetErrorDescriptionn(const char *vFormat, ...) const;
   void SetErrorDescriptionNoLog(const CMIUtilString &vrTxt) const;
   void ClrErrorDescription() const;
 
