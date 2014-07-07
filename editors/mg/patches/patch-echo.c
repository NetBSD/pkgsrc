$NetBSD: patch-echo.c,v 1.1 2014/07/07 18:06:58 jperkin Exp $

Compat define for MAX()

--- echo.c.orig	2011-01-02 22:57:56.000000000 +0000
+++ echo.c
@@ -20,6 +20,10 @@
 #include <stdarg.h>
 #include <term.h>
 
+#ifndef MAX
+#define MAX(x,y)	((x) > (y) ? (x) : (y))
+#endif
+
 static char	*veread(const char *, char *, size_t, int, va_list);
 static int	 complt(int, int, char *, size_t, int, int *);
 static int	 complt_list(int, char *, int);
