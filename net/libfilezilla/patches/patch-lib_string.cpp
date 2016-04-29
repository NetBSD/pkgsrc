$NetBSD: patch-lib_string.cpp,v 1.2 2016/04/29 14:14:16 wiz Exp $

Fix build with different types of iconv().
https://svn.filezilla-project.org/filezilla/libfilezilla/trunk/lib/string.cpp?view=patch&r1=7361&r2=7464&pathrev=7464

--- lib/string.cpp.orig	2016-04-15 07:52:15.000000000 +0000
+++ lib/string.cpp
@@ -7,6 +7,8 @@
 #else
 #include <iconv.h>
 #include <strings.h>
+
+#include <type_traits>
 #endif
 
 #include <cstdlib>
@@ -88,6 +90,13 @@ std::wstring to_wstring(std::string cons
 	return ret;
 }
 
+#ifndef FZ_WINDOWS
+// On some platforms, e.g. NetBSD, the second argument to iconv is const.
+// Depending which one is used, declare iconv_second_arg_type as either char* or char const*
+extern "C" typedef size_t (*iconv_prototype_with_const)(iconv_t, char const**, size_t *, char**, size_t *);
+typedef std::conditional<std::is_same<decltype(&iconv), iconv_prototype_with_const>::value, char const*, char*>::type iconv_second_arg_type;
+#endif
+
 std::wstring to_wstring_from_utf8(std::string const& in)
 {
 	std::wstring ret;
@@ -104,7 +113,7 @@ std::wstring to_wstring_from_utf8(std::s
 #else
 		iconv_t cd = iconv_open("WCHAR_T", "UTF-8");
 		if (cd != reinterpret_cast<iconv_t>(-1)) {
-			char * in_p = const_cast<char*>(in.c_str());
+			auto in_p = const_cast<iconv_second_arg_type>(in.c_str());
 			size_t in_len = in.size();
 
 			size_t out_len = in_len * sizeof(wchar_t) * 2;
@@ -168,7 +177,7 @@ std::string FZ_PUBLIC_SYMBOL to_utf8(std
 #else
 		iconv_t cd = iconv_open("UTF-8", "WCHAR_T");
 		if (cd != reinterpret_cast<iconv_t>(-1)) {
-			char * in_p = reinterpret_cast<char*>(const_cast<wchar_t*>(in.c_str()));
+			auto in_p = reinterpret_cast<iconv_second_arg_type>(const_cast<wchar_t*>(in.c_str()));
 			size_t in_len = in.size() * sizeof(wchar_t);
 
 			size_t out_len = in.size() * 4;
