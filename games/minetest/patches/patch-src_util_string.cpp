$NetBSD: patch-src_util_string.cpp,v 1.9 2024/09/09 07:46:20 nia Exp $

Support non-POSIX iconv on NetBSD before 10 and SunOS.

--- src/util/string.cpp.orig	2024-08-11 15:54:55.000000000 +0000
+++ src/util/string.cpp
@@ -39,6 +39,13 @@ with this program; if not, write to the 
 	#include <windows.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#endif
+#endif
+
 #ifndef _WIN32
 
 namespace {
@@ -77,7 +84,11 @@ static bool convert(iconv_t cd, char *ou
 	const size_t old_outbuf_size = *outbuf_size;
 	size_t old_size = inbuf_size;
 	while (inbuf_size > 0) {
+#if (defined(__NetBSD__) && !defined(NETBSD_POSIX_ICONV)) || defined(__sun)
+		iconv(cd, (const char **)&inbuf_ptr, &inbuf_size, &outbuf_ptr, outbuf_size);
+#else
 		iconv(cd, &inbuf_ptr, &inbuf_size, &outbuf_ptr, outbuf_size);
+#endif
 		if (inbuf_size == old_size) {
 			return false;
 		}
