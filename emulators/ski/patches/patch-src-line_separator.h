$NetBSD: patch-src-line_separator.h,v 1.1 2016/08/14 18:27:05 scole Exp $

Do not use carriage returns on unix which messes up ncurses display of code.

--- src/line_separator.h.orig	2016-04-17 06:52:45.000000000 -0400
+++ src/line_separator.h	2016-04-17 06:27:01.000000000 -0400
@@ -0,0 +1,6 @@
+/* XXX */
+#if  defined(__CYGWIN__) || defined(_WIN32)
+#define LINE_SEPARATOR "\r\n"
+#else
+#define LINE_SEPARATOR "\n"
+#endif
