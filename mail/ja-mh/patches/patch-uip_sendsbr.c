$NetBSD: patch-uip_sendsbr.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/sendsbr.c.orig	2013-03-28 18:13:35.000000000 +0000
+++ uip/sendsbr.c
@@ -13,7 +13,9 @@ static char ident[] = "@(#)$Id: sendsbr.
 #include <unistd.h>
 #endif
 
-static		alert(), anno(), annoaux();
+static		alert();
+static void annoaux(int);
+static void anno (int fd, struct stat *st);
 static int	tmp_fd();
 static int	sendaux();
 #ifdef	MIME
@@ -494,9 +496,7 @@ static int  tmp_fd () {
 
 /*  */
 
-static anno (fd, st)
-int	fd;
-register struct stat *st;
+static void anno (int fd, struct stat *st)
 {
     int     child_id;
     TYPESIG (*hstat) (), (*istat) (), (*qstat) (), (*tstat) ();
@@ -548,8 +548,7 @@ register struct stat *st;
 
 /*  */
 
-static	annoaux (fd)
-int	fd;
+static void annoaux (int fd)
 {
     int	    fd2,
 	    fd3,
