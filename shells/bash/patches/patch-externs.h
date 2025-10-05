$NetBSD: patch-externs.h,v 1.2 2025/10/05 11:18:27 js Exp $

Fix building when printf is defined to libintl_printf.

--- externs.h.orig	2025-03-07 23:48:53.000000000 +0000
+++ externs.h
@@ -217,7 +217,7 @@ extern int compat_init (void);
 
 /* Declarations for functions defined in lib/sh/dprintf.c */
 #if !defined (HAVE_DPRINTF)
-extern void dprintf (int, const char *, ...)  __attribute__((__format__ (printf, 2, 3)));
+extern void dprintf (int, const char *, ...)  __attribute__((__format__ (__printf__, 2, 3)));
 #endif
 
 /* Declarations for functions defined in lib/sh/fmtulong.c */
