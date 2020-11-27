$NetBSD: patch-fdprintf.c,v 1.1 2020/11/27 11:34:17 schmonz Exp $

Not all systems have dprintf().

--- fdprintf.c.orig	2020-11-27 10:59:35.151164978 +0000
+++ fdprintf.c
@@ -0,0 +1,14 @@
+#include <stdarg.h>
+#include <stdio.h>
+
+int fdprintf(int fd, const char *fmt, ...) {
+	va_list ap;
+	FILE *f = fdopen(fd, "w");
+	int rc;
+
+	va_start(ap, fmt);
+	rc = vfprintf(f, fmt, ap);
+	fclose(f);
+	va_end(ap);
+	return rc;
+}
