$NetBSD: patch-src_util_string.cpp,v 1.4 2021/09/15 12:20:15 nia Exp $

NetBSD does not support iconv("UTF-8", "WCHAR_T"), so use UTF-32, as
on Android.

--- src/util/string.cpp.orig	2021-04-10 16:41:12.000000000 +0000
+++ src/util/string.cpp
@@ -39,9 +39,14 @@ with this program; if not, write to the 
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
+#elif defined(_ICONV_H_) && (defined(__FreeBSD__) || \
+       defined(__OpenBSD__) || defined(__DragonFly__))
+#  define BSD_ICONV_USED
 #endif
 
 static bool parseHexColorString(const std::string &value, video::SColor &color,
@@ -80,9 +85,17 @@ static bool convert(const char *to, cons
 	return true;
 }
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__)
 // On Android iconv disagrees how big a wchar_t is for whatever reason
 const char *DEFAULT_ENCODING = "UTF-32LE";
+#elif defined(__NetBSD__)
+// NetBSD does not support WCHAR_T as an argument to iconv
+#include <sys/endian.h>
+#  if BYTE_ORDER == LITTLE_ENDIAN
+const char *DEFAULT_ENCODING = "UTF-32LE";
+#  else
+const char *DEFAULT_ENCODING = "UTF-32BE";
+#  endif
 #else
 const char *DEFAULT_ENCODING = "WCHAR_T";
 #endif
@@ -98,7 +111,7 @@ std::wstring utf8_to_wide(const std::str
 	std::wstring out;
 	out.resize(outbuf_size / sizeof(wchar_t));
 
-#ifdef __ANDROID__
+#if defined(__ANDROID__) || defined(__NetBSD__)
 	SANITY_CHECK(sizeof(wchar_t) == 4);
 #endif
 
