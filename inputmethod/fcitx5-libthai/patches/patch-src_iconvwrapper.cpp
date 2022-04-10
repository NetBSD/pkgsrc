$NetBSD: patch-src_iconvwrapper.cpp,v 1.1 2022/04/10 07:59:29 nia Exp $

Fix building on NetBSD <=9 with non-POSIX iconv.

--- src/iconvwrapper.cpp.orig	2020-12-11 07:57:11.364756600 +0000
+++ src/iconvwrapper.cpp
@@ -9,6 +9,15 @@
 #include <fcitx-utils/utf8.h>
 #include <iconv.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 class IconvWrapperPrivate {
 public:
     IconvWrapperPrivate(iconv_t conv) : conv_(conv) {}
@@ -37,9 +46,13 @@ std::vector<uint8_t> IconvWrapper::tryCo
         result.resize(s.size() * 10);
         size_t byteLength = s.size();
         size_t byteRemains = result.size();
-        char *data = const_cast<char *>(s.data());
         char *outData = reinterpret_cast<char *>(result.data());
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+        auto err = iconv(conv, s.data(), &byteLength, &outData, &byteRemains);
+#else
+        char *data = const_cast<char *>(s.data());
         auto err = iconv(conv, &data, &byteLength, &outData, &byteRemains);
+#endif
         if (err == static_cast<size_t>(-1)) {
             continue;
         }
