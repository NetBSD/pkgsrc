$NetBSD: patch-fsplit-fsplit.c,v 1.1 2011/09/25 19:44:08 joerg Exp $

--- fsplit/fsplit.c.orig	2011-09-25 09:50:22.000000000 +0000
+++ fsplit/fsplit.c
@@ -97,7 +97,7 @@ struct stat sbuf;
 
 #define trim(p)	while (*p == ' ' || *p == '\t') p++
 
-int   getline __P((void));
+int   my_getline __P((void));
 void  get_name __P((char *, int));
 char *functs __P((char *));
 int   lend __P((void));
@@ -171,7 +171,7 @@ char **argv;
 		errx(1, "can not open %s", x);
 	nflag = 0;
 	rv = 0;
-	while (getline() > 0) {
+	while (my_getline() > 0) {
 		rv = 1;
 		fprintf(ofp, "%s", buf);
 		if (lend())		/* look for an 'end' statement */
@@ -263,7 +263,7 @@ int letters;
 }
 
 int
-getline()
+my_getline()
 {
 	register char *ptr;
 
