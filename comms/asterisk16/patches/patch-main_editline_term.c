$NetBSD: patch-main_editline_term.c,v 1.1 2012/02/16 16:30:04 hans Exp $

--- main/editline/term.c.orig	2006-08-21 04:11:39.000000000 +0200
+++ main/editline/term.c	2012-01-25 15:34:57.916508677 +0100
@@ -71,8 +71,10 @@ extern int tgetent(char *, const char *)
 extern int tgetflag(const char *);
 extern int tgetnum(const char *);
 extern char *tgetstr(const char *, char **);
+#ifndef __sun
 extern int tputs (const char *, int, int (*)(int));
 extern char *tgoto (const char *, int, int);
+#endif
 #endif /* defined(HAVE_TERM_H) */
 #include <sys/types.h>
 #include <sys/ioctl.h>
