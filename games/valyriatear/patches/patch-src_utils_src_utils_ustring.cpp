$NetBSD: patch-src_utils_src_utils_ustring.cpp,v 1.2 2023/07/22 09:12:58 nia Exp $

Support non-POSIX iconv on NetBSD.

--- src/utils/src/utils/ustring.cpp.orig	2023-07-22 09:11:40.115042146 +0000
+++ src/utils/src/utils/ustring.cpp
@@ -25,6 +25,12 @@
 // For correct endianess support
 #include <SDL2/SDL_endian.h>
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#else
+#define __NetBSD_Prereq__(x,y,z) (0)
+#endif
+
 namespace vt_utils
 {
 
@@ -171,7 +177,8 @@ static bool UTF8ToUTF16(const std::strin
         return false;
     }
 
-#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109) || defined(__FreeBSD__)
+#if (defined(_LIBICONV_VERSION) && _LIBICONV_VERSION == 0x0109) || defined(__FreeBSD__) || \
+    (defined(__NetBSD__) && !__NetBSD_Prereq__(9,99,17))
     // We are using an iconv API that uses const char*
     const char *sourceChar = source.c_str();
 #else
