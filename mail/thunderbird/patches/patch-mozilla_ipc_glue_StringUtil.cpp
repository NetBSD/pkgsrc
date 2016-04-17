$NetBSD: patch-mozilla_ipc_glue_StringUtil.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/ipc/glue/StringUtil.cpp.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/glue/StringUtil.cpp
@@ -65,14 +65,14 @@ namespace base {
 // converters, and implementing the one that doesn't exist for OS X
 // and Windows.
 
-#if !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !defined(MOZ_WIDGET_COCOA) && !defined(OS_WIN)
 std::string SysWideToUTF8(const std::wstring& wide) {
   // FIXME/cjones: do this with iconv
   return GhettoStringConvert<std::wstring, std::string>(wide);
 }
 #endif
 
-#if !defined(OS_MACOSX) && !defined(OS_WIN)
+#if !defined(MOZ_WIDGET_COCOA) && !defined(OS_WIN)
 std::wstring SysUTF8ToWide(const StringPiece& utf8) {
   // FIXME/cjones: do this with iconv
   return GhettoStringConvert<StringPiece, std::wstring>(utf8);
