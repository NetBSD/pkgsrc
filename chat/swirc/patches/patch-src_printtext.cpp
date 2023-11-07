$NetBSD: patch-src_printtext.cpp,v 1.3 2023/11/07 07:58:36 fcambus Exp $

Support iconv prototype on NetBSD 9 and earlier.

--- src/printtext.cpp.orig	2023-11-05 13:36:56.000000000 +0000
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
@@ -1411,8 +1420,13 @@ get_buffer(CSTRING orig)
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
