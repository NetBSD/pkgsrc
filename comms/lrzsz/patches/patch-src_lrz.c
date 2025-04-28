$NetBSD: patch-src_lrz.c,v 1.1 2025/04/28 16:58:51 tnn Exp $

replace K&R prototypes

--- src/lrz.c.orig	1998-12-30 07:49:24.000000000 +0000
+++ src/lrz.c
@@ -42,9 +42,9 @@
 #include "error.h"
 
 #ifndef STRICT_PROTOTYPES
-extern time_t time();
-extern char *strerror();
-extern char *strstr();
+extern time_t time(time_t*);
+extern char *strerror(int);
+extern char *strstr(const char *, const char*);
 #endif
 
 #ifndef HAVE_ERRNO_DECLARATION
