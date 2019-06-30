$NetBSD: patch-src_util_string.cpp,v 1.1 2019/06/30 22:27:22 nia Exp $

Work around iconv("UTF-8", "WCHAR_T") failing on NetBSD.

--- src/util/string.cpp.orig	2019-03-31 20:57:45.000000000 +0000
+++ src/util/string.cpp
@@ -79,6 +79,12 @@ bool convert(const char *to, const char 
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
@@ -104,8 +110,9 @@ std::wstring utf8_to_wide(const std::str
 
 	return out;
 }
+#endif
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 // TODO: this is an ugly fix for wide_to_utf8 somehow not working on android
 std::string wide_to_utf8(const std::wstring &input)
 {
