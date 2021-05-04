$NetBSD: patch-src_utils.c,v 1.1 2021/05/04 08:19:42 fcambus Exp $

- Do not use err_exit() to generate error messages when locale initialization
  fails as in this case curs_set() is called before initscr(), which causes
  trader to crash when built with NetBSD curses.

- Avoid using strfmon(3) on NetBSD, there are formatting issues when LANG is
  set to anything else than C.

--- src/utils.c.orig	2021-01-19 05:42:38.000000000 +0000
+++ src/utils.c
@@ -591,8 +591,9 @@ extern void init_locale (void)
 
     // Initialise the current locale
     if (setlocale(LC_ALL, "") == NULL) {
-	err_exit("could not set locale "
-		 "(check LANG, LC_ALL and LANGUAGE in environment)");
+	fprintf(stderr, "%s: %s\n", program_name, "could not set locale "
+		"(check LANG, LC_ALL and LANGUAGE in environment)");
+	exit(EXIT_FAILURE);
     }
 
     // Use correct message catalogs for the locale
@@ -682,7 +683,11 @@ ssize_t xwcsfmon (wchar_t *restrict buf,
        produce "12345" instead of something like "-$123.45"!  The
        following code overcomes these limitations by using snprintf(). */
 
+#if defined(__NetBSD__)
+    if (0) {
+#else
     if (! is_posix_locale) {
+#endif
 	n = strfmon(s, BUFSIZE, format, val);
     } else {
 	/* The current implementation assumes the monetary decimal point
