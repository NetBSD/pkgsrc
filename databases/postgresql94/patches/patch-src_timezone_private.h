$NetBSD: patch-src_timezone_private.h,v 1.1 2015/01/14 21:01:18 adam Exp $

--- src/timezone/private.h.orig	2009-06-11 16:49:15.000000000 +0200
+++ src/timezone/private.h
@@ -51,8 +51,8 @@ extern int	unlink(const char *filename);
 extern char *icalloc(int nelem, int elsize);
 extern char *icatalloc(char *old, const char *new);
 extern char *icpyalloc(const char *string);
-extern char *imalloc(int n);
-extern void *irealloc(void *pointer, int size);
+extern char *imalloc(const int n);
+extern void *irealloc(void *pointer, const int size);
 extern void icfree(char *pointer);
 extern void ifree(char *pointer);
 extern const char *scheck(const char *string, const char *format);
