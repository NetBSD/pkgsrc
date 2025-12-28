$NetBSD: patch-source4_kdc_db-glue.c,v 1.1 2025/12/28 10:08:32 adam Exp $

Darwin does not provide reallocarray().

--- source4/kdc/db-glue.c.orig	2025-12-28 09:41:34.117717508 +0000
+++ source4/kdc/db-glue.c
@@ -49,6 +49,16 @@
 #include "talloc.h"
 #include "util/debug.h"
 
+#if defined(__APPLE__)
+static void *reallocarray(void *ptr, size_t nmemb, size_t size)
+{
+    if ((nmemb >= SIZE_MAX / size) || (size == 0 && nmemb > 0)) {
+        return NULL;
+    }
+    return realloc(ptr, nmemb * size);
+}
+#endif
+
 #undef DBGC_CLASS
 #define DBGC_CLASS DBGC_KERBEROS
 
