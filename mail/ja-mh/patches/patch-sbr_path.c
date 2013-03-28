$NetBSD: patch-sbr_path.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- sbr/path.c.orig	2013-03-28 18:10:53.000000000 +0000
+++ sbr/path.c
@@ -17,7 +17,7 @@ static char ident[] = "@(#)$Id: path.c,v
 static char *pwds;
 
 static char   *expath ();
-static	compath();
+static void compath (char *f);
 
 
 char   *path (name, flag)
@@ -98,8 +98,7 @@ register int     flag;
 
 /*  */
 
-static  compath (f)
-register char  *f;
+static void compath (char *f)
 {
     register char  *cp,
                    *dp;
