$NetBSD: patch-fdprintf.c,v 1.2 2020/11/27 13:48:25 schmonz Exp $

Not all systems have dprintf().

--- fdprintf.c.orig	2020-11-27 13:14:12.000000000 +0000
+++ fdprintf.c
@@ -0,0 +1,18 @@
+#include <stdarg.h>
+#include <stdio.h>
+#include <sys/errno.h>
+
+static FILE *f;
+
+int fdprintf(int fd, const char *fmt, ...) {
+	va_list ap;
+	int rc;
+
+	f = fdopen(fd, "w");
+	if (f == NULL) return -1;
+
+	va_start(ap, fmt);
+	rc = vfprintf(f, fmt, ap);
+	va_end(ap);
+	return rc;
+}
