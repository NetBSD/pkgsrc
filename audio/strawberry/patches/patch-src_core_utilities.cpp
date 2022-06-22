$NetBSD: patch-src_core_utilities.cpp,v 1.1 2022/06/22 09:36:49 nia Exp $

Support non-POSIX iconv prototype in NetBSD 9/earlier and SunOS.

--- src/core/utilities.cpp.orig	2022-06-22 09:33:19.522006535 +0000
+++ src/core/utilities.cpp
@@ -103,6 +103,15 @@
 #  include "scoped_cftyperef.h"
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
 namespace Utilities {
 
 static QString tr(const char *str) {
@@ -807,7 +816,11 @@ QString UnicodeToAscii(const QString &un
 
   snprintf(input, input_len, "%s", utf8.constData());
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+  iconv(conv, (const char **)&input, &input_len, &output, &output_len);
+#else
   iconv(conv, &input, &input_len, &output, &output_len);
+#endif
   iconv_close(conv);
 
   QString ret(output_ptr);
