$NetBSD: patch-Source_Core_Common_StringUtil.cpp,v 1.2 2019/10/25 09:56:51 kamil Exp $

Support NetBSD.

--- Source/Core/Common/StringUtil.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Common/StringUtil.cpp
@@ -28,6 +28,15 @@
 	#include <errno.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 #if !defined(_WIN32) && !defined(ANDROID)
 static locale_t GetCLocale()
 {
@@ -121,11 +130,11 @@ bool CharArrayFromFormatV(char* out, int
 		c_locale = _create_locale(LC_ALL, "C");
 	writtenCount = _vsnprintf_l(out, outsize, format, c_locale, args);
 #else
-	#if !defined(ANDROID)
+	#if !defined(ANDROID) && !defined(__NetBSD__)
 	locale_t previousLocale = uselocale(GetCLocale());
 	#endif
 	writtenCount = vsnprintf(out, outsize, format, args);
-	#if !defined(ANDROID)
+	#if !defined(ANDROID) && !defined(__NetBSD__)
 	uselocale(previousLocale);
 	#endif
 #endif
@@ -162,12 +171,12 @@ std::string StringFromFormatV(const char
 	std::string temp = buf;
 	delete[] buf;
 #else
-	#if !defined(ANDROID)
+	#if !defined(ANDROID) && !defined(__NetBSD__)
 	locale_t previousLocale = uselocale(GetCLocale());
 	#endif
 	if (vasprintf(&buf, format, args) < 0)
 		ERROR_LOG(COMMON, "Unable to allocate memory for string");
-	#if !defined(ANDROID)
+	#if !defined(ANDROID) && !defined(__NetBSD__)
 	uselocale(previousLocale);
 	#endif
 
@@ -427,8 +436,13 @@ std::string CodeToUTF8(const char* fromc
 
 		while (src_bytes != 0)
 		{
+#if defined(__NetBSD__) && !NETBSD_POSIX_ICONV
+			size_t const iconv_result = iconv(conv_desc, (const char**)(&src_buffer), &src_bytes,
+				&dst_buffer, &dst_bytes);
+#else
 			size_t const iconv_result = iconv(conv_desc, (char**)(&src_buffer), &src_bytes,
 				&dst_buffer, &dst_bytes);
+#endif
 
 			if ((size_t)-1 == iconv_result)
 			{
