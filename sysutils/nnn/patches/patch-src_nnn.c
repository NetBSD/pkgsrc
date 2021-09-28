$NetBSD: patch-src_nnn.c,v 1.4 2021/09/28 23:31:04 sjmulder Exp $

dprintf() polyfill for Solaris

--- src/nnn.c.orig	2021-09-28 23:10:13.183444540 +0000
+++ src/nnn.c
@@ -117,6 +117,10 @@
 #define alloca(size) __builtin_alloca(size)
 #endif
 
+#ifdef __sun
+#define NEED_DPRINTF
+#endif
+
 #include "nnn.h"
 #include "dbg.h"
 
@@ -834,6 +838,25 @@ static void notify_fifo(bool force);
 
 /* Functions */
 
+#ifdef NEED_DPRINTF
+static int dprintf(int fd, const char *format, ...)
+{
+	va_list ap;
+	char *s;
+
+	va_start(ap, format);
+	if (vasprintf(&s, format, ap) == -1)
+		{ va_end(ap); return -1; }
+	va_end(ap);
+
+	if (write(fd, s, strlen(s)) == -1)
+		{ free(s); return -1; }
+
+	free(s);
+	return 0;
+}
+#endif
+
 static void sigint_handler(int sig)
 {
 	(void) sig;
