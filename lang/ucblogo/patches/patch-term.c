$NetBSD: patch-term.c,v 1.2 2015/11/09 07:18:34 dholland Exp $

- unconditionally use termios, not legacy termio or sgtty.h
- unconditionally include term.h for termcap stuff

--- term.c.orig	2008-09-14 04:57:09.000000000 +0000
+++ term.c
@@ -30,26 +30,11 @@
 #include <console.h>
 #endif
 
-#ifdef HAVE_TERMIO_H
-#ifdef HAVE_WX
-#include <termios.h>
-#else
-#include <termio.h>
-#endif
-#else
-#ifdef HAVE_SGTTY_H
-#include <sgtty.h>
-#endif
-#endif
-
 #undef TRUE
 #undef FALSE
 
 #ifdef HAVE_TERMCAP_H
 #include <termcap.h>
-#ifdef HAVE_SGTTY_H
-#include <sgtty.h>
-#endif
 #else
 #ifdef HAVE_TERMLIB_H
 #include <termlib.h>
@@ -60,6 +45,9 @@
 #endif
 #endif
 
+#include <term.h>
+#include <termios.h>
+
 #undef TRUE
 #undef FALSE
 
@@ -78,13 +66,7 @@ char cm_arr[40];
 char so_arr[40];
 char se_arr[40];
 
-#ifdef HAVE_TERMIO_H
-struct termio tty_cooked, tty_cbreak;
-#else
-#ifdef HAVE_SGTTY_H
-struct sgttyb tty_cooked, tty_cbreak;
-#endif
-#endif
+struct termios tty_cooked, tty_cbreak;
 
 int interactive, tty_charmode;
 
@@ -132,18 +114,11 @@ void term_init(void) {
 #endif /* WIN32 */
 #else
     if (interactive) {
-#ifdef HAVE_TERMIO_H
-	ioctl(0,TCGETA,(char *)(&tty_cooked));
+	tcgetattr(0, &tty_cooked);
 	tty_cbreak = tty_cooked;
 	tty_cbreak.c_cc[VMIN] = '\01';
 	tty_cbreak.c_cc[VTIME] = '\0';
 	tty_cbreak.c_lflag &= ~(ECHO|ICANON);
-#else
-	ioctl(0,TIOCGETP,(char *)(&tty_cooked));
-	tty_cbreak = tty_cooked;
-	tty_cbreak.sg_flags |= CBREAK;
-	tty_cbreak.sg_flags &= ~ECHO;
-#endif
     }
     tty_charmode = 0;
     tgetent(bp, getenv("TERM"));
@@ -188,11 +163,7 @@ void term_init(void) {
 void charmode_on() {
 #ifdef unix
     if ((readstream == stdin) && interactive && !tty_charmode) {
-#ifdef HAVE_TERMIO_H
-	ioctl(0,TCSETA,(char *)(&tty_cbreak));
-#else /* !HAVE_TERMIO_H */
-	ioctl(0,TIOCSETP,(char *)(&tty_cbreak));
-#endif /* HAVE_TERMIO_H */
+	tcsetattr(0, TCSANOW, &tty_cbreak);
 	tty_charmode++;
     }
 #endif /* unix */
@@ -204,11 +175,7 @@ void charmode_on() {
 void charmode_off() {
 #ifdef unix
     if (tty_charmode) {
-#ifdef HAVE_TERMIO_H
-	ioctl(0,TCSETA,(char *)(&tty_cooked));
-#else /* !HAVE_TERMIO_H */
-	ioctl(0,TIOCSETP,(char *)(&tty_cooked));
-#endif /* HAVE_TERMIO_H */
+	tcsetattr(0, TCSANOW, &tty_cooked);
 	tty_charmode = 0;
     }
 #endif /* unix */
