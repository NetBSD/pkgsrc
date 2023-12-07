$NetBSD: patch-def.h,v 1.1 2023/12/07 23:57:25 tnn Exp $

provide reallocarray on macOS

--- def.h.orig	2023-12-07 23:51:35.995974204 +0000
+++ def.h
@@ -795,3 +795,19 @@ extern int		 rptcount;	/* successive inv
 #define st_ctim st_ctimespec
 #define st_mtim st_mtimespec
 #endif
+
+#if defined(__APPLE__)
+#include <stdlib.h>
+#include <errno.h>
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
