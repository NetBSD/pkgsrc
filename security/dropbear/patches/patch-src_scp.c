$NetBSD: patch-src_scp.c,v 1.1 2026/05/28 12:35:08 adam Exp $

Implement reallocarray for Darwin.

--- src/scp.c.orig	2026-05-06 11:45:04.615352173 +0000
+++ src/scp.c
@@ -82,6 +82,22 @@
 #include "scpmisc.h"
 #include "progressmeter.h"
 
+#if defined(__APPLE__)
+#include <errno.h>
+#include <stdlib.h>
+#define MUL_NO_OVERFLOW ((size_t)1 << (sizeof(size_t) * 4))
+static void *
+reallocarray(void *optr, size_t nmemb, size_t size)
+{
+	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) &&
+		nmemb > 0 && SIZE_MAX / nmemb < size) {
+		errno = EIO;
+		return NULL;
+	}
+	return realloc(optr, size * nmemb);
+}
+#endif
+
 void bwlimit(int);
 
 /* Struct for addargs */
