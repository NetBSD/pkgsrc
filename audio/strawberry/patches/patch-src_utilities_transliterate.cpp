$NetBSD: patch-src_utilities_transliterate.cpp,v 1.2 2023/11/20 00:58:10 nia Exp $

Support non-POSIX iconv prototype in NetBSD 9/earlier and SunOS.

--- src/utilities/transliterate.cpp.orig	2023-09-25 17:20:58.428898151 +0000
+++ src/utilities/transliterate.cpp
@@ -28,6 +28,15 @@
 #  include <iconv.h>
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
 #include <QByteArray>
 #include <QString>
 
@@ -76,7 +85,11 @@ QString Transliterate(const QString &acc
 
   snprintf(input, input_len, "%s", utf8.constData());
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+  iconv(conv, (const char **)&input, &input_len, &output, &output_len);
+#else
   iconv(conv, &input, &input_len, &output, &output_len);
+#endif
   iconv_close(conv);
 
   QString ret(output_ptr);
