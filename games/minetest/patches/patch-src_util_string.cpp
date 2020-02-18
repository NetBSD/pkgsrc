$NetBSD: patch-src_util_string.cpp,v 1.2 2020/02/18 16:46:51 joerg Exp $

Work around iconv("UTF-8", "WCHAR_T") failing on NetBSD.

--- src/util/string.cpp.orig	2019-10-12 13:48:58.000000000 +0000
+++ src/util/string.cpp
@@ -38,9 +38,11 @@ with this program; if not, write to the 
 	#include <windows.h>
 #endif
 
-#if defined(_ICONV_H_) && (defined(__FreeBSD__) || defined(__NetBSD__) || \
-	defined(__OpenBSD__) || defined(__DragonFly__))
-	#define BSD_ICONV_USED
+#ifdef __NetBSD__
+#  include <sys/param.h>
+#  if __NetBSD_Version__ <= 999001500
+#  define BSD_ICONV_USED
+#  endif
 #endif
 
 static bool parseHexColorString(const std::string &value, video::SColor &color,
@@ -79,6 +81,12 @@ bool convert(const char *to, const char 
 	return true;
 }
 
+#ifdef __NetBSD__
+std::wstring utf8_to_wide(const std::string &input)
+{
+	return narrow_to_wide(input);
+}
+#else
 std::wstring utf8_to_wide(const std::string &input)
 {
 	size_t inbuf_size = input.length() + 1;
@@ -104,8 +112,9 @@ std::wstring utf8_to_wide(const std::str
 
 	return out;
 }
+#endif
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 // TODO: this is an ugly fix for wide_to_utf8 somehow not working on android
 std::string wide_to_utf8(const std::wstring &input)
 {
