$NetBSD: patch-src_terminal.c,v 1.1 2025/06/01 14:14:35 vins Exp $

Prevent type clash with illumos termcap and/or ncurses.

--- src/terminal.c.orig	2023-08-27 07:25:53.000000000 +0000
+++ src/terminal.c
@@ -64,10 +64,7 @@ __RCSID("$NetBSD: terminal.c,v 1.46 2023
 #endif
 
 /* Solaris's term.h does horrid things. */
-#if defined(HAVE_TERM_H) && !defined(__sun) && !defined(HAVE_TERMCAP_H)
-#include <term.h>
-#endif
-
+#ifndef HAVE_TERMCAP_H
 #if defined(__sun)
 extern int tgetent(char *, const char *);
 extern int tgetflag(char *);
@@ -75,7 +72,10 @@ extern int tgetnum(char *);
 extern int tputs(const char *, int, int (*)(int));
 extern char* tgoto(const char*, int, int);
 extern char* tgetstr(char*, char**);
+#elif defined(HAVE_TERM_H)
+#include <term.h>
 #endif
+#endif /* HAVE_TERMCAP_H */
 
 #ifdef _REENTRANT
 #include <pthread.h>
