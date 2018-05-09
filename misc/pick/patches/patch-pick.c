$NetBSD: patch-pick.c,v 1.1 2018/05/09 15:26:05 leot Exp $

tparm(3) expects a `const char *' as first argument, adjust tty_parm1()
accordingly.

--- pick.c.orig	2018-04-10 19:52:06.000000000 +0000
+++ pick.c
@@ -90,7 +90,7 @@ static void			 toggle_sigwinch(int);
 static int			 tty_getc(void);
 static const char		*tty_getcap(char *);
 static void			 tty_init(int);
-static const char		*tty_parm1(char *, int);
+static const char		*tty_parm1(const char *, int);
 static int			 tty_putc(int);
 static void			 tty_restore(int);
 static void			 tty_size(void);
@@ -1063,7 +1063,7 @@ tty_getcap(char *cap)
 }
 
 const char *
-tty_parm1(char *cap, int a)
+tty_parm1(const char *cap, int a)
 {
 	return tparm(cap, a, 0, 0, 0, 0, 0, 0, 0, 0);
 }
