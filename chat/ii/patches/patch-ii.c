$NetBSD: patch-ii.c,v 1.1 2025/09/02 20:24:02 vins Exp $

Make sure PATH_MAX is defined. 

--- ii.c.orig	2022-10-04 17:25:51.000000000 +0000
+++ ii.c
@@ -24,6 +24,10 @@ char *argv0;
 
 #include "arg.h"
 
+#ifndef PATH_MAX
+#define PATH_MAX _POSIX_PATH_MAX
+#endif
+
 #ifdef NEED_STRLCPY
 size_t strlcpy(char *, const char *, size_t);
 #endif /* NEED_STRLCPY */
