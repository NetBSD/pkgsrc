$NetBSD: patch-Source_Core_Common_StringUtil.cpp,v 1.1 2019/01/01 17:19:58 nia Exp $

Support NetBSD.

--- Source/Core/Common/StringUtil.cpp.orig	2016-06-24 08:09:07.000000000 +0000
+++ Source/Core/Common/StringUtil.cpp
@@ -121,11 +121,11 @@ bool CharArrayFromFormatV(char* out, int
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
@@ -162,12 +162,12 @@ std::string StringFromFormatV(const char
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
 
@@ -427,8 +427,13 @@ std::string CodeToUTF8(const char* fromc
 
 		while (src_bytes != 0)
 		{
+#ifdef __NetBSD__
+			size_t const iconv_result = iconv(conv_desc, (const char**)(&src_buffer), &src_bytes,
+				&dst_buffer, &dst_bytes);
+#else
 			size_t const iconv_result = iconv(conv_desc, (char**)(&src_buffer), &src_bytes,
 				&dst_buffer, &dst_bytes);
+#endif
 
 			if ((size_t)-1 == iconv_result)
 			{
