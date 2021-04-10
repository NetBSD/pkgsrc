$NetBSD: patch-src_utils_src_utils_ustring.cpp,v 1.1 2021/04/10 09:38:21 nia Exp $

Support non-POSIX iconv on NetBSD.

--- src/utils/src/utils/ustring.cpp.orig	2019-07-29 10:50:15.000000000 +0000
+++ src/utils/src/utils/ustring.cpp
@@ -25,6 +25,10 @@
 // For correct endianess support
 #include <SDL2/SDL_endian.h>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 namespace vt_utils
 {
 
@@ -171,7 +175,8 @@ static bool UTF8ToUTF16(const std::strin
         return false;
     }
 
-#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109) || defined(__FreeBSD__)
+#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109) || defined(__FreeBSD__) || \
+    (defined(__NetBSD__) && !__NetBSD_Prereq__(9,99,17))
     // We are using an iconv API that uses const char*
     const char *sourceChar = source.c_str();
 #else
