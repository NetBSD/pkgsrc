$NetBSD: patch-src_util_string.cpp,v 1.3 2020/12/01 13:16:26 nia Exp $

NetBSD does not support iconv("UTF-8", "WCHAR_T"), so use UTF-32, as
on Android.

--- src/util/string.cpp.orig	2020-07-09 20:04:20.000000000 +0000
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
@@ -82,6 +84,13 @@ bool convert(const char *to, const char 
 #ifdef __ANDROID__
 // Android need manual caring to support the full character set possible with wchar_t
 const char *DEFAULT_ENCODING = "UTF-32LE";
+#elif defined(__NetBSD__)
+#include <sys/endian.h>
+#  if BYTE_ORDER == LITTLE_ENDIAN
+const char *DEFAULT_ENCODING = "UTF-32LE";
+#  else
+const char *DEFAULT_ENCODING = "UTF-32BE";
+#  endif
 #else
 const char *DEFAULT_ENCODING = "WCHAR_T";
 #endif
@@ -97,7 +106,7 @@ std::wstring utf8_to_wide(const std::str
 	char *outbuf = new char[outbuf_size];
 	memset(outbuf, 0, outbuf_size);
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 	// Android need manual caring to support the full character set possible with wchar_t
 	SANITY_CHECK(sizeof(wchar_t) == 4);
 #endif
@@ -209,7 +218,7 @@ wchar_t *narrow_to_wide_c(const char *st
 }
 
 std::wstring narrow_to_wide(const std::string &mbs) {
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 	return utf8_to_wide(mbs);
 #else
 	size_t wcl = mbs.size();
@@ -225,7 +234,7 @@ std::wstring narrow_to_wide(const std::s
 
 std::string wide_to_narrow(const std::wstring &wcs)
 {
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 	return wide_to_utf8(wcs);
 #else
 	size_t mbl = wcs.size() * 4;
