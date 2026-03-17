$NetBSD: patch-src_convert.c,v 1.1 2026/03/17 15:39:51 nia Exp $

Handle NetBSD and SunOS iconv variations.

--- src/convert.c.orig	2026-03-17 15:25:37.047494095 +0000
+++ src/convert.c
@@ -11,6 +11,15 @@
 #include "util/xmalloc.h"
 #include "util/xreadwrite.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 struct FileEncoder {
     struct cconv *cconv;
     unsigned char *nbuf;
@@ -193,7 +202,7 @@ static size_t iconv_wrapper (
 ) {
     // POSIX defines the second parameter of iconv(3) as "char **restrict"
     // but NetBSD declares it as "const char **restrict"
-#ifdef __NetBSD__
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
     const char **restrict in = inbuf;
 #else
     char **restrict in = (char **restrict)inbuf;
