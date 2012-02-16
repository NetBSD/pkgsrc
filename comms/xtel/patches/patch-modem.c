$NetBSD: patch-modem.c,v 1.1 2012/02/16 18:00:20 hans Exp $

--- modem.c.orig	2012-01-27 10:38:52.460117270 +0100
+++ modem.c	2012-01-27 10:44:00.399646906 +0100
@@ -144,9 +144,10 @@ void init_tty (int fd, int speed, int cs
   term.c_lflag &= ~(ICANON|ISIG|ECHO|IEXTEN);
 #endif
 
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__sun)
   term.c_cflag = (CREAD | HUPCL | CRTSCTS);
-  cfsetspeed( &term, speed);
+  cfsetospeed( &term, speed);
+  cfsetispeed( &term, speed);
 #else
   /*
    * FreeBSD 1.1 (Beta) n'a pas l'air d'apprecier qu'on mette clocal
@@ -212,7 +213,8 @@ void restore_tty(int fd)
 #endif
  
    /* remet la ligne en l'etat */
-  cfsetspeed(&term_sauve, B0);
+  cfsetospeed(&term_sauve, B0);
+  cfsetispeed(&term_sauve, B0);
   if (tcsetattr (fd, TCSADRAIN, &term_sauve) < 0) {
 	log_err("tcsetattr(2):%s", strerror(errno));
 	exit(1);
