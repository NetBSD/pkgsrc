$NetBSD: patch-src_utilities_transliterate.cpp,v 1.1 2023/02/04 15:38:39 nia Exp $

Support non-POSIX iconv prototype in NetBSD 9/earlier and SunOS.

--- src/utilities/transliterate.cpp.orig	2022-12-28 21:54:04.427431913 +0000
+++ src/utilities/transliterate.cpp
@@ -34,6 +34,15 @@
 
 #include "transliterate.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 namespace Utilities {
 
 QString Transliterate(const QString &accented_str) {
@@ -76,7 +85,11 @@ QString Transliterate(const QString &acc
 
   snprintf(input, input_len, "%s", utf8.constData());
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+  iconv(conv, (const char **)&input, &input_len, &output, &output_len);
+#else
   iconv(conv, &input, &input_len, &output, &output_len);
+#endif
   iconv_close(conv);
 
   QString ret(output_ptr);
