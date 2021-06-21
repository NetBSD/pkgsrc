$NetBSD: patch-gemrb_core_System_String.cpp,v 1.3 2021/06/21 14:02:47 nia Exp $

Deal with old NetBSD/SunOS style iconv.

--- gemrb/core/System/String.cpp.orig	2021-06-02 16:16:47.000000000 +0000
+++ gemrb/core/System/String.cpp
@@ -31,6 +31,15 @@
 #include <iconv.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif /* __NetBSD_Prereq__(9,99,17) */
+#endif /* defined(__NetBSD__) */
+
 namespace GemRB {
 
 static String* StringFromEncodedData(const ieByte* string, const EncodingStruct& encoded)
@@ -123,7 +132,11 @@ char* ConvertCharEncoding(const char* st
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
