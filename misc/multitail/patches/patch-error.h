$NetBSD: patch-error.h,v 1.1 2025/05/27 19:15:12 vins Exp $

Prevent redefinitions.

--- error.h.orig	2024-08-13 10:49:48.000000000 +0000
+++ error.h
@@ -1,6 +1,10 @@
 #define BOOL char
+#ifndef TRUE
 #define TRUE 1
+#endif
+#ifndef FALSE
 #define FALSE 0
+#endif
 
 void error_exit_(BOOL show_errno, BOOL show_st, char *file, const char *function, int line, char *format, ...);
 
