$NetBSD: patch-src_libjasper_base_jas__malloc.c,v 1.1 2016/05/16 14:03:40 he Exp $

Fix CVE-2008-3520, patches from
https://bugs.gentoo.org/show_bug.cgi?id=222819

--- src/libjasper/base/jas_malloc.c.orig	2007-01-19 21:43:05.000000000 +0000
+++ src/libjasper/base/jas_malloc.c
@@ -76,6 +76,9 @@
 
 /* We need the prototype for memset. */
 #include <string.h>
+#include <limits.h>
+#include <errno.h>
+#include <stdint.h>
 
 #include "jasper/jas_malloc.h"
 
@@ -113,18 +116,50 @@ void jas_free(void *ptr)
 
 void *jas_realloc(void *ptr, size_t size)
 {
-	return realloc(ptr, size);
+	return ptr ? realloc(ptr, size) : malloc(size);
 }
 
-void *jas_calloc(size_t nmemb, size_t size)
+void *jas_realloc2(void *ptr, size_t nmemb, size_t size)
+{
+	if (!ptr)
+		return jas_alloc2(nmemb, size);
+	if (nmemb && SIZE_MAX / nmemb < size) {
+		errno = ENOMEM;
+		return NULL;
+	}
+	return jas_realloc(ptr, nmemb * size);
+
+}
+
+void *jas_alloc2(size_t nmemb, size_t size)
+{
+	if (nmemb && SIZE_MAX / nmemb < size) {
+		errno = ENOMEM;
+		return NULL;
+	}
+
+	return jas_malloc(nmemb * size);
+}
+
+void *jas_alloc3(size_t a, size_t b, size_t c)
 {
-	void *ptr;
 	size_t n;
-	n = nmemb * size;
-	if (!(ptr = jas_malloc(n * sizeof(char)))) {
-		return 0;
+
+	if (a && SIZE_MAX / a < b) {
+		errno = ENOMEM;
+		return NULL;
 	}
-	memset(ptr, 0, n);
+
+	return jas_alloc2(a*b, c);
+}
+
+void *jas_calloc(size_t nmemb, size_t size)
+{
+	void *ptr;
+
+	ptr = jas_alloc2(nmemb, size);
+	if (ptr)
+		memset(ptr, 0, nmemb*size);
 	return ptr;
 }
 
