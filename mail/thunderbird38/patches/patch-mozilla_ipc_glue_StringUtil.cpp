$NetBSD: patch-mozilla_ipc_glue_StringUtil.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/ipc/glue/StringUtil.cpp.orig	2014-07-18 00:05:24.000000000 +0000
+++ mozilla/ipc/glue/StringUtil.cpp
@@ -64,14 +64,14 @@ namespace base {
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
