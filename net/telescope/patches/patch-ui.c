$NetBSD: patch-ui.c,v 1.1 2025/09/08 09:52:02 vins Exp $

Support dprintf() on SunOS.

--- ui.c.orig	2024-12-30 09:09:40.000000000 +0000
+++ ui.c
@@ -1,4 +1,4 @@
-/*
+#define _XPG7   1/*
  * Copyright (c) 2021, 2024 Omar Polo <op@omarpolo.com>
  *
  * Permission to use, copy, modify, and distribute this software for any
@@ -32,6 +32,12 @@
 
 #include "compat.h"
 
+#if defined(__illumos__)
+#define _XPG7	1
+#elif defined(__sun)
+#include "dprintf.h"
+#endif
+
 #include <sys/time.h>
 #include <sys/wait.h>
 
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
