$NetBSD: patch-fsplit-fsplit.c,v 1.2 2011/10/02 23:12:06 dholland Exp $

- avoid conflict with posix getline
- add const for clean build
- use <ctype.h> functions correctly
- use standard C

--- fsplit/fsplit.c.orig	2000-01-30 21:03:32.000000000 +0000
+++ fsplit/fsplit.c
@@ -97,28 +97,25 @@ struct stat sbuf;
 
 #define trim(p)	while (*p == ' ' || *p == '\t') p++
 
-int   getline __P((void));
+int   my_getline __P((void));
 void  get_name __P((char *, int));
 char *functs __P((char *));
 int   lend __P((void));
 int   lname __P((char *, int));
-char *look __P((char *, char *));
+char *look __P((char *, const char *));
 int   saveit __P((char *));
 int   scan_name __P((char *, char *, int));
 char *skiplab __P((char *));
 static void usage __P((void));
 
 int
-main(argc, argv)
-int argc;
-char **argv;
+main(int argc, char **argv)
 {
 	extern int optind;
 	extern char *optarg;
 
 	register FILE *ofp;	/* output file */
 	register int rv;	/* 1 if got card in output file, 0 otherwise */
-	register char *ptr;
 	int nflag,		/* 1 if got name of subprog., 0 otherwise */
 		retval,
 		i;
@@ -171,7 +168,7 @@ char **argv;
 		errx(1, "can not open %s", x);
 	nflag = 0;
 	rv = 0;
-	while (getline() > 0) {
+	while (my_getline() > 0) {
 		rv = 1;
 		fprintf(ofp, "%s", buf);
 		if (lend())		/* look for an 'end' statement */
@@ -263,7 +260,7 @@ int letters;
 }
 
 int
-getline()
+my_getline()
 {
 	register char *ptr;
 
@@ -332,7 +329,7 @@ int len;
 	/*  copy to buffer and converting to lower case */
 	p = ptr;
 	while (*p && p <= &buf[71] ) {
-	   *iptr = isupper(*p) ? tolower(*p) : *p;
+	   *iptr = isupper((unsigned char)*p) ? tolower((unsigned char)*p) : *p;
 	   iptr++;
 	   p++;
 	}
@@ -437,9 +434,11 @@ char *p;
 /* 	return 0 if m doesn't match initial part of s;
 	otherwise return ptr to next char after m in s */
 char *look(s, m)
-char *s, *m;
+char *s;
+const char *m;
 {
-	register char *sp, *mp;
+	register char *sp;
+	register const char *mp;
 
 	sp = s; mp = m;
 	while (*mp) {
