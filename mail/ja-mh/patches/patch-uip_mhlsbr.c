$NetBSD: patch-uip_mhlsbr.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/mhlsbr.c.orig	2001-04-04 16:05:16.000000000 +0000
+++ uip/mhlsbr.c
@@ -57,6 +57,8 @@ static char ident[] = "@(#)$Id: mhlsbr.c
 
 #define	QUOTE	'\\'
 
+static void m_pclose (void);
+
 /*  */
 
 static struct swit mhlswitches[] = {
@@ -292,8 +294,13 @@ static TYPESIG	intrser (), pipeser (), q
 static char   *mcomp_add (), *oneline (), *parse ();
 static struct mcomp *add_queue ();
 
-static	mhl_format(), evalvar(), process(), mhlfile(), free_queue(), putcomp();
-static	putstr(), putch(), face_format(), m_popen();
+static	mhl_format(), evalvar(), free_queue();
+static void process (char *folder, char *fname, int ofilen, int ofilec);
+static void mhlfile (FILE *fp, char *mname, int ofilen, int ofilec);
+static  void putcomp (struct mcomp *c1, struct mcomp *c2, int flag);
+static	putstr(), m_popen();
+static void face_format (struct mcomp *c1);
+static void putch(char ch);
 static int	ptoi(), ptos(), doface();
 
 void	clear_screen ();
@@ -784,11 +791,7 @@ static char *parse () {
 
 /*  */
 
-static  process (folder, fname, ofilen, ofilec)
-char   *folder,
-       *fname;
-int	ofilen,
-	ofilec;
+static void process (char *folder, char *fname, int ofilen, int ofilec)
 {
     char  *cp;
     FILE  *fp;
@@ -832,11 +835,7 @@ int	ofilen,
 
 /*  */
 
-static mhlfile (fp, mname, ofilen, ofilec)
-register FILE   *fp;
-register char   *mname;
-int	ofilen,
-	ofilec;
+static void mhlfile (FILE *fp, char *mname, int ofilen, int ofilec)
 {
     int     state;
     register struct mcomp  *c1,
@@ -1089,9 +1088,7 @@ struct pqpair {
 };
 
 
-static mcomp_format (c1, c2)
-register struct mcomp *c1,
-		      *c2;
+static void mcomp_format (struct mcomp *c1, struct mcomp *c2)
 {
     int     dat[5];
     register char  *ap,
@@ -1256,10 +1253,7 @@ register struct mcomp **head,
 
 /*  */
 
-static  putcomp (c1, c2, flag)
-register struct mcomp *c1,
-		      *c2;
-int     flag;
+static void putcomp (struct mcomp *c1, struct mcomp *c2, int flag)
 {
     int     count,
             cchdr;
@@ -1478,9 +1472,8 @@ putstr_sbr(string)
 
 /*  */
 
-static
-putch(ch)
-     char ch;
+static void
+putch(char ch)
 {
     char buf[BUFSIZ];
 
@@ -1686,8 +1679,7 @@ int     i;
 
 /*  */
 
-static	face_format (c1)
-register struct mcomp *c1;
+static void face_format (struct mcomp *c1)
 {
     register char  *cp;
     register struct mailname   *mp;
@@ -2018,7 +2010,7 @@ char *name;
 }
 
 
-m_pclose () {
+static void m_pclose (void) {
     if (m_pid == NOTOK)
 	return;
 
