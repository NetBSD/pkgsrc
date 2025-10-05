$NetBSD: patch-print_cmd.c,v 1.1 2025/10/05 11:18:27 js Exp $

Fix building when printf is defined to libintl_printf.

--- print_cmd.c.orig	2025-03-07 23:50:21.000000000 +0000
+++ print_cmd.c
@@ -54,8 +54,8 @@ static int indentation_amount = 4;
 
 typedef void PFUNC (const char *, ...);
 
-static void cprintf (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
-static void xprintf (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
+static void cprintf (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
+static void xprintf (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
 
 static void uw_reset_locals (void *);
 
