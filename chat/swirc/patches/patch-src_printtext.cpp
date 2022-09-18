$NetBSD: patch-src_printtext.cpp,v 1.1 2022/09/18 12:21:18 nia Exp $

Support iconv prototype on NetBSD 9 and earlier.

--- src/printtext.cpp.orig	2022-07-28 13:19:25.000000000 +0000
+++ src/printtext.cpp
@@ -39,6 +39,15 @@
 #include <iconv.h>
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
 #include "assertAPI.h"
 #include "atomicops.h"
 #ifdef UNIT_TESTING
@@ -1473,8 +1482,13 @@ get_buffer(const char *orig)
 		out[outbytes] = '\0';
 		out_p = addrof(out[0]);
 		errno = 0;
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+		if (iconv(cd, (const char **)&in, &inbytes, &out_p, &outbytes) == static_cast
+		    <size_t>(-1)) {
+#else
 		if (iconv(cd, &in, &inbytes, &out_p, &outbytes) == static_cast
 		    <size_t>(-1)) {
+#endif
 			free(orig_copy);
 			free(out);
 			(void) iconv_close(cd);
