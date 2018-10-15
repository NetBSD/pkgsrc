$NetBSD: patch-Source_Core_Common_StringUtil.cpp,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Common/StringUtil.cpp.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Common/StringUtil.cpp
@@ -131,11 +131,11 @@ bool CharArrayFromFormatV(char* out, int
     c_locale = _create_locale(LC_ALL, "C");
   writtenCount = _vsnprintf_l(out, outsize, format, c_locale, args);
 #else
-#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__)
+#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
   locale_t previousLocale = uselocale(GetCLocale());
 #endif
   writtenCount = vsnprintf(out, outsize, format, args);
-#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__)
+#if !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
   uselocale(previousLocale);
 #endif
 #endif
@@ -172,7 +172,7 @@ std::string StringFromFormatV(const char
   std::string temp = buf;
   delete[] buf;
 #else
-#if !defined(_WIN32) && !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
   locale_t previousLocale = uselocale(GetCLocale());
 #endif
   if (vasprintf(&buf, format, args) < 0)
@@ -181,7 +181,7 @@ std::string StringFromFormatV(const char
     buf = nullptr;
   }
 
-#if !defined(_WIN32) && !defined(ANDROID) && !defined(__HAIKU__) && !defined(__OpenBSD__)
+#if !defined(_WIN32) && !defined(ANDROID) && !defined(__HAIKU__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
   uselocale(previousLocale);
 #endif
 
@@ -550,8 +550,13 @@ std::string CodeTo(const char* tocode, c
 
     while (src_bytes != 0)
     {
+#ifdef __NetBSD__
+      size_t const iconv_result =
+          iconv(conv_desc, (const char**)(&src_buffer), &src_bytes, &dst_buffer, &dst_bytes);
+#else
       size_t const iconv_result =
           iconv(conv_desc, (char**)(&src_buffer), &src_bytes, &dst_buffer, &dst_bytes);
+#endif
 
       if ((size_t)-1 == iconv_result)
       {
