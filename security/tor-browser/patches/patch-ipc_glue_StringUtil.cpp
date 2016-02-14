$NetBSD: patch-ipc_glue_StringUtil.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Just because OS_ARCH is Darwin does not mean
sys_string_conversions_mac.mm can be used.

--- ipc/glue/StringUtil.cpp.orig	2014-05-06 22:55:41.000000000 +0000
+++ ipc/glue/StringUtil.cpp
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
