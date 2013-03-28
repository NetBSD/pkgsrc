$NetBSD: patch-uip_rcvtty.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/rcvtty.c.orig	2013-03-28 18:54:40.000000000 +0000
+++ uip/rcvtty.c
@@ -79,7 +79,7 @@ off_t	lseek ();
 char   *getusr ();
 
 static int	message_fd(), header_fd();
-static		alert();
+static  void alert (char *tty, int md);
 
 static int bell = 1;
 static int newline = 1;
@@ -329,9 +329,7 @@ static int  header_fd () {
 /*  */
 
 #ifndef	TTYD
-static  alert (tty, md)
-char   *tty;
-int     md;
+static  void alert (char *tty, int md)
 {
     int     i,
             td;
@@ -395,9 +393,7 @@ int     md;
 
 /*  */
 
-static  alert (user, md)
-register char   *user;
-int     md;
+static void  alert (char *user, int md)
 {
     int     i,
             td;
