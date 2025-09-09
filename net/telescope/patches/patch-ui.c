$NetBSD: patch-ui.c,v 1.2 2025/09/09 15:22:06 vins Exp $

Support dprintf() on SunOS.
Note that illumos supports dprintf() in UNIX V7 compliance.

--- ui.c.orig	2024-12-30 09:09:40.000000000 +0000
+++ ui.c
@@ -30,6 +30,12 @@
  *
  */
 
+#if defined(__illumos__)
+#define _XPG7	1
+#elif defined(__sun)
+#include "dprintf.h"
+#endif
+
 #include "compat.h"
 
 #include <sys/time.h>
@@ -122,6 +128,23 @@ static struct timeval	loading_tv = { 0,
 
 static char	keybuf[64];
 
+#if defined(__sun) && !defined(__illumos__)
+int
+dprintf(int fd, const char *restrict format, ...)
+{
+	va_list ap;
+	FILE *f = fdopen(fd, "w");
+	if (!f) {
+	    return -1;
+	}
+	va_start(ap, format);
+	int result = fprintf(f, format, ap);
+	va_end(ap);
+
+	return result;
+}
+#endif
+
 /* XXX: don't forget to init these in main() */
 struct kmap global_map,
 	minibuffer_map,
