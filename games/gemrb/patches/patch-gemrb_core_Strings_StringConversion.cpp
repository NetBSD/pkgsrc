$NetBSD: patch-gemrb_core_Strings_StringConversion.cpp,v 1.1 2023/04/27 18:50:59 yhardy Exp $

Deal with old NetBSD/SunOS style iconv.

--- gemrb/core/Strings/StringConversion.cpp.orig	2022-08-29 19:10:39.000000000 +0000
+++ gemrb/core/Strings/StringConversion.cpp
@@ -20,6 +20,15 @@
 
 #include <iconv.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif /* __NetBSD_Prereq__(9,99,17) */
+#endif /* defined(__NetBSD__) */
+
 #include "ie_types.h"
 #include "Interface.h"
 #include "Logging/Logging.h"
@@ -115,7 +124,11 @@ char* ConvertCharEncoding(const char* st
 	size_t out_len_left = out_len;
 	char* buf = (char*) malloc(out_len);
 	char* buf_out = buf;
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+	size_t ret = iconv(cd, (const char **)&in, &in_len, &buf_out, &out_len_left);
+#else
 	size_t ret = iconv(cd, &in, &in_len, &buf_out, &out_len_left);
+#endif
 	iconv_close(cd);
 
 	if (ret == (size_t)-1) {
