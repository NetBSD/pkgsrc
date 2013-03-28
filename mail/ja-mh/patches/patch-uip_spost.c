$NetBSD: patch-uip_spost.c,v 1.1 2013/03/28 21:31:26 joerg Exp $

--- uip/spost.c.orig	2001-04-04 16:05:17.000000000 +0000
+++ uip/spost.c
@@ -212,9 +212,11 @@ static char *fccfold[FCCS];	/* foldernam
 static struct headers  *hdrtab;	/* table for the message we're doing */
 static FILE *out;		/* output (temp) file */
 
-static	putfmt(), start_headers(), finish_headers(), putadr(),
-	insert_fcc();
-static	file(), fcc();
+static void putfmt (char *name, char *str, FILE *out);
+static	start_headers(), finish_headers(), putadr();
+static void insert_fcc (struct headers *hdr, char *pp);
+static	fcc();
+static void file (char *path);
 static int	get_header(), putone();
 /*    MAIN */
 
@@ -529,10 +531,7 @@ char   *argv[];
 
 /*    DRAFT GENERATION */
 
-static putfmt (name, str, out)
-char   *name,
-       *str;
-FILE * out;
+static void putfmt (char *name, char *str, FILE *out)
 {
     int     count,
             grp,
@@ -835,9 +834,7 @@ int indent;
 
 /*  */
 
-static  insert_fcc (hdr, pp)
-struct	headers *hdr;
-char   *pp;
+static void insert_fcc (struct headers *hdr, char *pp)
 {
     char   *cp;
 
@@ -921,8 +918,7 @@ static  make_bcc_file () {
 
 /*    FCC INTERACTION */
 
-static  file (path)
-char   *path;
+static void file (char *path)
 {
     int     i;
 
