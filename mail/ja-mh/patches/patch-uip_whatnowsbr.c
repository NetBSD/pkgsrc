$NetBSD: patch-uip_whatnowsbr.c,v 1.1 2013/03/28 21:31:27 joerg Exp $

--- uip/whatnowsbr.c.orig	2013-03-28 18:12:50.000000000 +0000
+++ uip/whatnowsbr.c
@@ -18,7 +18,8 @@ static char ident[] = "@(#)$Id: whatnows
 #define	MIMEminc(a)	0
 #endif
 
-static int	editfile(), copyf(), sendfile(), sendit(), whomfile();
+static int	editfile(), copyf(), sendfile(), whomfile();
+static void sendit (char *sp, char **arg, char *file, int pushed);
 #ifdef	MIME
 static int	mhnfile();
 #endif
@@ -690,11 +691,7 @@ extern char *distfile;
 
 /*  */
 
-static  sendit (sp, arg, file, pushed)
-register char  *sp,
-	      **arg,
-               *file;
-int     pushed;
+static void sendit (char *sp, char **arg, char *file, int pushed)
 {
 #ifndef	lint
     int	    distsw = 0;
