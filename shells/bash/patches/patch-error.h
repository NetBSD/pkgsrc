$NetBSD: patch-error.h,v 1.1 2025/10/05 03:16:21 js Exp $

Fix building when printf is defined to libintl_printf.

--- error.h.orig	2024-10-24 18:24:03.000000000 +0000
+++ error.h
@@ -30,36 +30,36 @@ extern char *get_name_for_error (void);
 extern void file_error (const char *);
 
 /* Report a programmer's error, and abort.  Pass REASON, and ARG1 ... ARG5. */
-extern void programming_error (const char *, ...) __attribute__((__format__ (printf, 1, 2)));
+extern void programming_error (const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
 
 /* General error reporting.  Pass FORMAT and ARG1 ... ARG5. */
-extern void report_error (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
+extern void report_error (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Error messages for parts of the parser that don't call report_syntax_error */
-extern void parser_error (int, const char *, ...) __attribute__((__format__ (printf, 2, 3)));
+extern void parser_error (int, const char *, ...) __attribute__((__format__ (__printf__, 2, 3)));
 
 /* Report an unrecoverable error and exit.  Pass FORMAT and ARG1 ... ARG5. */
-extern void fatal_error (const char *, ...) __attribute__((__format__ (printf, 1, 2)));
+extern void fatal_error (const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Report a system error, like BSD warn(3). */
-extern void sys_error (const char *, ...) __attribute__((__format__ (printf, 1, 2)));
+extern void sys_error (const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Report an internal error. */
-extern void internal_error (const char *, ...) __attribute__((__format__ (printf, 1, 2)));
+extern void internal_error (const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Report an internal warning. */
-extern void internal_warning (const char *, ...)  __attribute__((__format__ (printf, 1, 2)));
+extern void internal_warning (const char *, ...)  __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Report an internal warning for debugging purposes. */
-extern void internal_debug (const char *, ...) __attribute__((__format__ (printf, 1, 2)));
+extern void internal_debug (const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Report an internal informational notice. */
-extern void internal_inform (const char *, ...) __attribute__((__format__ (printf, 1, 2)));
+extern void internal_inform (const char *, ...) __attribute__((__format__ (__printf__, 1, 2)));
 
 /* Debugging functions, not enabled in released version. */
 extern char *strescape (const char *);
-extern void itrace (const char *, ...) __attribute__ ((__format__ (printf, 1, 2)));
-extern void trace (const char *, ...) __attribute__ ((__format__ (printf, 1, 2)));
+extern void itrace (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)));
+extern void trace (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)));
 
 /* Report an error having to do with command parsing or execution. */
 extern void command_error (const char *, int, int, int);
