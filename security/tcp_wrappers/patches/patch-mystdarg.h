$NetBSD: patch-mystdarg.h,v 1.1 2025/04/29 14:18:00 tnn Exp $

--- mystdarg.h.orig	2025-04-29 12:53:14.212107539 +0000
+++ mystdarg.h
@@ -16,4 +16,4 @@
 #define VAEND(ap)              va_end(ap);}
 #endif
 
-extern char *percent_m();
+extern char *percent_m(char *, char *);
