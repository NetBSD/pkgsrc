$NetBSD: patch-lib_utils_printf.c,v 1.1 2017/11/29 15:13:32 hauke Exp $

Undefine macro names we intend to implement as functions

--- lib/utils/printf.c.orig	2017-08-23 01:50:10.000000000 +0000
+++ lib/utils/printf.c
@@ -40,6 +40,10 @@
 #endif
 
 #undef putchar  // Some stdlibs have a #define for putchar
+
+#undef snprintf
+#undef vsnprintf
+
 int printf(const char *fmt, ...);
 int vprintf(const char *fmt, va_list ap);
 int putchar(int c);
