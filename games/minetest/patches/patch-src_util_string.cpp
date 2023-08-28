$NetBSD: patch-src_util_string.cpp,v 1.6 2023/08/28 07:01:29 nia Exp $

Support non-POSIX iconv on NetBSD before 10 and SunOS.

--- src/util/string.cpp.orig	2023-04-08 16:04:52.000000000 +0000
+++ src/util/string.cpp
@@ -39,6 +39,15 @@ with this program; if not, write to the 
 	#include <windows.h>
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
 #ifndef _WIN32
 
 static bool convert(const char *to, const char *from, char *outbuf,
@@ -54,7 +63,11 @@ static bool convert(const char *to, cons
 	const size_t old_outbuf_size = *outbuf_size;
 	size_t old_size = inbuf_size;
 	while (inbuf_size > 0) {
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		iconv(cd, (const char **)&inbuf_ptr, inbuf_left_ptr, &outbuf_ptr, outbuf_size);
+#else
 		iconv(cd, &inbuf_ptr, inbuf_left_ptr, &outbuf_ptr, outbuf_size);
+#endif
 		if (inbuf_size == old_size) {
 			iconv_close(cd);
 			return false;
