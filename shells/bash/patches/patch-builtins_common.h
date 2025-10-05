$NetBSD: patch-builtins_common.h,v 1.1 2025/10/05 03:16:21 js Exp $

Fix building when printf is defined to libintl_printf.

--- builtins/common.h.orig	2024-10-23 19:40:02.000000000 +0000
+++ builtins/common.h
@@ -82,8 +82,8 @@ do { \
 #define MAX_ATTRIBUTES		16
 
 /* Functions from common.c */
-extern void builtin_error (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
-extern void builtin_warning (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
+extern void builtin_error (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
+extern void builtin_warning (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
 extern void builtin_usage (void);
 extern void no_args (WORD_LIST *, int);
 extern int no_options (WORD_LIST *);
