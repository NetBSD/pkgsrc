$NetBSD: patch-uip_slocal.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/slocal.c.orig	2013-03-28 18:56:29.000000000 +0000
+++ uip/slocal.c
@@ -211,7 +211,9 @@ struct passwd *getpwnam ();
 #endif
 static int	localmail(), usr_delivery(), split(), parse(), logged_in();
 static int	timely(), usr_file(), usr_pipe(), copyfile();
-static expand(), glob(), copyinfo();
+static expand();
+static void glob (int fd);
+static void copyinfo (FILE *fp, char *from);
 
 /*  */
 
@@ -893,8 +895,7 @@ int	fd;
 
 /*  */
 
-static	glob (fd)
-register int  fd;
+static void glob (int fd)
 {
     char buffer[BUFSIZ];
     struct stat st;
@@ -1238,9 +1239,7 @@ int     i;
 
 /*  */
 
-static	copyinfo (fp, from)
-register FILE   *fp;
-char	*from;
+static void copyinfo (FILE *fp, char *from)
 {
     int     i;
     register char  *cp;
