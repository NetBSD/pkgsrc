$NetBSD: patch-tools_lldb-mi_MICmnBase.h,v 1.1 2016/03/28 13:13:55 kamil Exp $

Cannot pass object of non-trivial type 'const CMIUtilString'
through variadic function.

--- tools/lldb-mi/MICmnBase.h.orig	2015-08-04 10:24:20.000000000 +0000
+++ tools/lldb-mi/MICmnBase.h
@@ -28,7 +28,7 @@ class CMICmnBase
     bool HaveErrorDescription() const;
     const CMIUtilString &GetErrorDescription() const;
     void SetErrorDescription(const CMIUtilString &vrTxt) const;
-    void SetErrorDescriptionn(const CMIUtilString vFormat, ...) const;
+    void SetErrorDescriptionn(const char *vFormat, ...) const;
     void SetErrorDescriptionNoLog(const CMIUtilString &vrTxt) const;
     void ClrErrorDescription() const;
 
