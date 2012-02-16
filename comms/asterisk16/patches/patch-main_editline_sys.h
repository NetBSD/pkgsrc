$NetBSD: patch-main_editline_sys.h,v 1.1 2012/02/16 16:30:04 hans Exp $

--- main/editline/sys.h.orig	2009-03-02 21:16:51.000000000 +0100
+++ main/editline/sys.h	2012-01-25 15:39:39.413404722 +0100
@@ -101,9 +101,9 @@ extern int	tgetent(const char *bp, char 
 extern int	tgetflag(const char *id);
 extern int	tgetnum(const char *id);
 extern char    *tgetstr(const char *id, char **area);
-#endif
 extern char    *tgoto(const char *cap, int col, int row);
 extern int	tputs(const char *str, int affcnt, int (*putc)(int));
+#endif
 extern char    *getenv(const char *);
 extern int	fprintf(FILE *, const char *, ...);
 extern int	sigsetmask(int);
