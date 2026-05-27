$NetBSD: patch-sockssrv.c,v 1.1 2026/05/27 10:54:46 tm Exp $

dprintf is not available on SunOS / illumos.

--- sockssrv.c.orig	2026-05-27 10:27:34.259067822 +0000
+++ sockssrv.c
@@ -61,6 +61,23 @@
 #define THREAD_STACK_SIZE 32*1024
 #endif
 
+#if defined(__sun)
+#include <stdarg.h>
+
+int dprintf(int fd, const char *restrict format, ...) {
+    va_list ap;
+    FILE *f = fdopen(fd, "w");
+    if (!f) {
+        return -1;
+    }
+    va_start(ap, format);
+    int result = fprintf(f, format, ap);
+    va_end(ap);
+
+    return result;
+}
+#endif
+
 static int quiet;
 static const char* auth_user;
 static const char* auth_pass;
