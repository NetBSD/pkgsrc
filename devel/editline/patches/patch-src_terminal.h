$NetBSD: patch-src_terminal.h,v 1.1 2020/04/21 13:07:01 jperkin Exp $

Remove conflicting and unnecessary SunOS-specific defines.

--- src/terminal.h.orig	2018-05-25 17:50:45.000000000 +0000
+++ src/terminal.h
@@ -80,15 +80,6 @@ typedef struct {
 #define	A_K_DE		6
 #define	A_K_NKEYS	7
 
-#ifdef __sun
-extern int tgetent(char *, const char *);
-extern int tgetflag(char *);
-extern int tgetnum(char *);
-extern int tputs(const char *, int, int (*)(int));
-extern char* tgoto(const char*, int, int);
-extern char* tgetstr(char*, char**);
-#endif
-
 libedit_private void	terminal_move_to_line(EditLine *, int);
 libedit_private void	terminal_move_to_char(EditLine *, int);
 libedit_private void	terminal_clear_EOL(EditLine *, int);
