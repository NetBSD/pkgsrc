$NetBSD: patch-xbmc_utils_CharsetConverter.cpp,v 1.1 2015/11/17 16:14:21 jmcneill Exp $

--- xbmc/utils/CharsetConverter.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/utils/CharsetConverter.cpp
@@ -57,7 +57,7 @@
   #define WCHAR_CHARSET UTF16_CHARSET 
   #pragma comment(lib, "libfribidi.lib")
   #pragma comment(lib, "libiconv.lib")
-#elif defined(TARGET_ANDROID)
+#elif defined(TARGET_ANDROID) || defined(TARGET_NETBSD)
   #define WCHAR_IS_UCS_4 1
   #define UTF16_CHARSET "UTF-16" ENDIAN_SUFFIX
   #define UTF32_CHARSET "UTF-32" ENDIAN_SUFFIX
