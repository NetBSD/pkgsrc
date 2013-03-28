$NetBSD: patch-uip_replsbr.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/replsbr.c.orig	2013-03-28 18:37:39.000000000 +0000
+++ uip/replsbr.c
@@ -68,7 +68,8 @@ static char *addrcomps[] = {
     NULL
 };
 
-static	insert(), replfilter();
+static	insert();
+static void replfilter (FILE *in, FILE *out);
 /*  */
 
 /* ARGSUSED */
@@ -438,9 +439,7 @@ register struct mailname *np;
 
 /*  */
 
-static	replfilter (in, out)
-register FILE *in,
-	      *out;
+static void replfilter (FILE *in, FILE *out)
 {
     int	    pid;
     char   *mhl;
