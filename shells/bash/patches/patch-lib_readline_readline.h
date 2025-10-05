$NetBSD: patch-lib_readline_readline.h,v 1.1 2025/10/05 03:16:21 js Exp $

Fix building when printf is defined to libintl_printf.

--- lib/readline/readline.h.orig	2024-11-15 17:22:56.000000000 +0000
+++ lib/readline/readline.h
@@ -409,7 +409,7 @@ extern void rl_activate_mark (void);
 extern void rl_deactivate_mark (void);
 extern int rl_mark_active_p (void);
 
-extern int rl_message (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
+extern int rl_message (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
 
 extern int rl_show_char (int);
 
