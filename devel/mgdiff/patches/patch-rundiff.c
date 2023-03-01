$NetBSD: patch-rundiff.c,v 1.2 2023/03/01 23:48:00 vins Exp $

Avoid conflicting getline() type definition.
Pull patches from Debian.

--- rundiff.c.orig	1994-05-19 02:01:22.000000000 +0000
+++ rundiff.c
@@ -1,5 +1,5 @@
-#ifndef lint
-static char rcsid[] = "rundiff.c,v 2.0 1994/05/19 02:01:22 dan Exp";
+#if 0
+static char rcsid[] __attribute__((unused)) = "rundiff.c,v 2.0 1994/05/19 02:01:22 dan Exp";
 #endif
 
 /*
@@ -44,6 +44,16 @@ static char rcsid[] = "rundiff.c,v 2.0 1
 #include "mgdiff.h"
 #include "externs.h"
 
+static inline void* xcalloc(size_t nmemb, size_t size)
+{
+    void *ret = calloc(nmemb, size);
+    if (!ret) {
+	perror("calloc");
+	exit (1);
+    }
+    return ret;
+}
+
 /* 
  * this is the maximum number of lines shown to the user if diff
  * returns an error
@@ -63,7 +73,7 @@ typedef enum { ADD = 1, CHANGE, DELETE,
 static char *duplicate (char *s, int *flag);
 static DiffType parse_diff_line (char *buf, int *f1n1, int *f1n2, int *f2n1, int *f2n2);
 static int eatline (FILE *f);
-static void getline (FILE *f, char **cooked, char **raw);
+static void get_line (FILE *f, char **cooked, char **raw);
 static void reset_blist (void);
 static Block *get_blist (void);
 static void add_blist (Block *b);
@@ -170,22 +180,22 @@ DiffInfo *blank_diff_info (void)
     Block *b;
     DiffInfo *di;
 
-    di = (DiffInfo *) calloc (1, sizeof (DiffInfo));
+    di = (DiffInfo *) xcalloc (1, sizeof (DiffInfo));
     di->longline = "  ";
     di->maxcols = strlen (di->longline);
     di->status = 2;
 
-    b = (Block *) calloc (1, sizeof (Block));
+    b = (Block *) xcalloc (1, sizeof (Block));
     b->selected = NEITHER;
     b->arr[LEFT].type = b->arr[RIGHT].type = SAME;
     b->sline = 0;
     b->ssize = 1;
     b->arr[LEFT].fline = b->arr[RIGHT].fline = 0;
     b->arr[LEFT].fsize = b->arr[RIGHT].fsize = 1;
-    b->arr[LEFT].text = (char **) calloc (1, sizeof (char *));
-    b->arr[LEFT].wtext = (char **) calloc (1, sizeof (char *));
-    b->arr[LEFT].tlen = (short *) calloc (1, sizeof (short));
-    b->arr[LEFT].text[0] = strdup ("  ");
+    b->arr[LEFT].text = (char **) xcalloc (1, sizeof (char *));
+    b->arr[LEFT].wtext = (char **) xcalloc (1, sizeof (char *));
+    b->arr[LEFT].tlen = (short *) xcalloc (1, sizeof (short));
+    b->arr[LEFT].text[0] = xstrdup ("  ");
     b->arr[LEFT].tlen[0] = strlen (b->arr[LEFT].text[0]);
 
     b->arr[RIGHT].text = NULL;
@@ -209,7 +219,7 @@ DiffInfo *build_diff_info (char *prog, c
     FILE *diff, *file1, *file2;
     char buffer[BUFSIZ+1];
     int sline, fline1, fline2;
-    Block *b;
+    Block *b = NULL;
     int i, lines, counter;
     int stat_loc;
     DiffInfo *di;
@@ -220,7 +230,7 @@ DiffInfo *build_diff_info (char *prog, c
     file2 = fopen (path2, "r");
     diff = spawn_diff (prog, args, path1, path2);
 
-    di = (DiffInfo *) calloc (1, sizeof (DiffInfo));
+    di = (DiffInfo *) xcalloc (1, sizeof (DiffInfo));
     di->longline = "";
 
     XmUpdateDisplay (toplevel);
@@ -244,21 +254,21 @@ DiffInfo *build_diff_info (char *prog, c
 	    if (di->errors == 0) {
 		char cmdline[4096];
 
-		di->etext = (char **) calloc (MAX_ERROR_LINES + 1, sizeof (char *));
-		(void) sprintf (cmdline, "    \"%s %s %s %s\"", prog, args, path1, path2);
-		di->etext[di->errors++] = strdup ("diff command line:");
-		di->etext[di->errors++] = strdup ("");
-		di->etext[di->errors++] = strdup (cmdline);
-		di->etext[di->errors++] = strdup ("");
-		di->etext[di->errors++] = strdup ("produced this output:");
-		di->etext[di->errors++] = strdup ("");
+		di->etext = (char **) xcalloc (MAX_ERROR_LINES + 1, sizeof (char *));
+		(void) snprintf (cmdline, sizeof (cmdline), "    \"%s %s %s %s\"", prog, args, path1, path2);
+		di->etext[di->errors++] = xstrdup ("diff command line:");
+		di->etext[di->errors++] = xstrdup ("");
+		di->etext[di->errors++] = xstrdup (cmdline);
+		di->etext[di->errors++] = xstrdup ("");
+		di->etext[di->errors++] = xstrdup ("produced this output:");
+		di->etext[di->errors++] = xstrdup ("");
 	    }
 	    if (di->errors < MAX_ERROR_LINES)
-		di->etext[di->errors++] = strdup (buffer);
+		di->etext[di->errors++] = xstrdup (buffer);
 	    break;
 	case ADD:
 	    if (f2n1 != fline2) {
-		b = (Block *) calloc (1, sizeof (Block));
+		b = (Block *) xcalloc (1, sizeof (Block));
 		b->selected = NEITHER;
 		b->arr[LEFT].type = b->arr[RIGHT].type = SAME;
 		b->sline = sline;
@@ -267,11 +277,11 @@ DiffInfo *build_diff_info (char *prog, c
 		b->arr[LEFT].fsize = b->arr[RIGHT].fsize = f2n1 - fline2;
 		b->ssize = f2n1 - fline2;
 		
-		b->arr[LEFT].text = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-		b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-		b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
+		b->arr[LEFT].text = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+		b->arr[LEFT].wtext = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+		b->arr[LEFT].tlen = (short *) xcalloc (b->arr[LEFT].fsize, sizeof (short));
 		for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		    getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		    get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 			di->maxcols = b->arr[LEFT].tlen[i];
@@ -285,7 +295,7 @@ DiffInfo *build_diff_info (char *prog, c
 		add_blist (b);
 	    }
 
-	    b = (Block *) calloc (1, sizeof (Block));
+	    b = (Block *) xcalloc (1, sizeof (Block));
 	    b->selected = NEITHER;
 	    b->arr[LEFT].type = BLANK;
 	    b->arr[RIGHT].type = INSERT;
@@ -296,11 +306,11 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[RIGHT].fsize = f2n2 - f2n1 + 1;
 	    b->ssize = max (b->arr[LEFT].fsize, b->arr[RIGHT].fsize);
 
-	    b->arr[RIGHT].text = (char **) calloc (b->arr[RIGHT].fsize, sizeof (char *));
-	    b->arr[RIGHT].wtext = (char **) calloc (b->arr[RIGHT].fsize, sizeof (char *));
-	    b->arr[RIGHT].tlen = (short *) calloc (b->arr[RIGHT].fsize, sizeof (short));
+	    b->arr[RIGHT].text = (char **) xcalloc (b->arr[RIGHT].fsize, sizeof (char *));
+	    b->arr[RIGHT].wtext = (char **) xcalloc (b->arr[RIGHT].fsize, sizeof (char *));
+	    b->arr[RIGHT].tlen = (short *) xcalloc (b->arr[RIGHT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[RIGHT].fsize; i++) {
-		getline (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
+		get_line (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
 		b->arr[RIGHT].tlen[i] = strlen (b->arr[RIGHT].text[i]);
 		if (di->maxcols < b->arr[RIGHT].tlen[i]) {
 		    di->maxcols = b->arr[RIGHT].tlen[i];
@@ -318,7 +328,7 @@ DiffInfo *build_diff_info (char *prog, c
 	    break;
 	case CHANGE:
 	    if (f1n1 != fline1) {
-		b = (Block *) calloc (1, sizeof (Block));
+		b = (Block *) xcalloc (1, sizeof (Block));
 		b->selected = NEITHER;
 		b->arr[LEFT].type = b->arr[RIGHT].type = SAME;
 		b->sline = sline;
@@ -327,11 +337,11 @@ DiffInfo *build_diff_info (char *prog, c
 		b->arr[LEFT].fsize = b->arr[RIGHT].fsize = f1n1 - fline1;
 		b->ssize = f1n1 - fline1;
 		
-		b->arr[LEFT].text = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-		b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-		b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
+		b->arr[LEFT].text = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+		b->arr[LEFT].wtext = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+		b->arr[LEFT].tlen = (short *) xcalloc (b->arr[LEFT].fsize, sizeof (short));
 		for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		    getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		    get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 			di->maxcols = b->arr[LEFT].tlen[i];
@@ -344,7 +354,7 @@ DiffInfo *build_diff_info (char *prog, c
 		sline += b->ssize;
 		add_blist (b);
 	    }
-	    b = (Block *) calloc (1, sizeof (Block));
+	    b = (Block *) xcalloc (1, sizeof (Block));
 	    b->selected = NEITHER;
 	    b->arr[LEFT].type = b->arr[RIGHT].type = DIFF;
 	    b->sline = sline;
@@ -354,11 +364,11 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[RIGHT].fsize = f2n2 - f2n1 + 1;
 	    b->ssize = max (b->arr[LEFT].fsize, b->arr[RIGHT].fsize);
 
-	    b->arr[LEFT].text = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-	    b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-	    b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
+	    b->arr[LEFT].text = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+	    b->arr[LEFT].wtext = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+	    b->arr[LEFT].tlen = (short *) xcalloc (b->arr[LEFT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		if (di->maxcols < b->arr[LEFT].tlen[i]) {
 		    di->maxcols = b->arr[LEFT].tlen[i];
@@ -367,11 +377,11 @@ DiffInfo *build_diff_info (char *prog, c
 	    }
 	    fline1 += b->arr[LEFT].fsize;
 
-	    b->arr[RIGHT].text = (char **) calloc (b->arr[RIGHT].fsize, sizeof (char *));
-	    b->arr[RIGHT].wtext = (char **) calloc (b->arr[RIGHT].fsize, sizeof (char *));
-	    b->arr[RIGHT].tlen = (short *) calloc (b->arr[RIGHT].fsize, sizeof (short));
+	    b->arr[RIGHT].text = (char **) xcalloc (b->arr[RIGHT].fsize, sizeof (char *));
+	    b->arr[RIGHT].wtext = (char **) xcalloc (b->arr[RIGHT].fsize, sizeof (char *));
+	    b->arr[RIGHT].tlen = (short *) xcalloc (b->arr[RIGHT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[RIGHT].fsize; i++) {
-		getline (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
+		get_line (file2, &b->arr[RIGHT].text[i], &b->arr[RIGHT].wtext[i]);
 		b->arr[RIGHT].tlen[i] = strlen (b->arr[RIGHT].text[i]);
 		if (di->maxcols < b->arr[RIGHT].tlen[i]) {
 		    di->maxcols = b->arr[RIGHT].tlen[i];
@@ -386,7 +396,7 @@ DiffInfo *build_diff_info (char *prog, c
 	    break;
 	case DELETE:
 	    if (f1n1 != fline1) {
-		b = (Block *) calloc (1, sizeof (Block));
+		b = (Block *) xcalloc (1, sizeof (Block));
 		b->selected = NEITHER;
 		b->arr[LEFT].type = b->arr[RIGHT].type = SAME;
 		b->sline = sline;
@@ -395,11 +405,11 @@ DiffInfo *build_diff_info (char *prog, c
 		b->arr[LEFT].fsize = b->arr[RIGHT].fsize = f1n1 - fline1;
 		b->ssize = f1n1 - fline1;
 		
-		b->arr[LEFT].text = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-		b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-		b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
+		b->arr[LEFT].text = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+		b->arr[LEFT].wtext = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+		b->arr[LEFT].tlen = (short *) xcalloc (b->arr[LEFT].fsize, sizeof (short));
 		for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		    getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		    get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 			di->maxcols = b->arr[LEFT].tlen[i];
@@ -413,7 +423,7 @@ DiffInfo *build_diff_info (char *prog, c
 		add_blist (b);
 	    }
 
-	    b = (Block *) calloc (1, sizeof (Block));
+	    b = (Block *) xcalloc (1, sizeof (Block));
 	    b->selected = NEITHER;
 	    b->arr[LEFT].type = INSERT;
 	    b->arr[RIGHT].type = BLANK;
@@ -424,11 +434,11 @@ DiffInfo *build_diff_info (char *prog, c
 	    b->arr[RIGHT].fsize = 0;
 	    b->ssize = max (b->arr[LEFT].fsize, b->arr[RIGHT].fsize);
 
-	    b->arr[LEFT].text = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-	    b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-	    b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
+	    b->arr[LEFT].text = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+	    b->arr[LEFT].wtext = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+	    b->arr[LEFT].tlen = (short *) xcalloc (b->arr[LEFT].fsize, sizeof (short));
 	    for (i = 0; i < b->arr[LEFT].fsize; i++) {
-		getline (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+		get_line (file1, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 		b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 		if (di->maxcols < b->arr[LEFT].tlen[i]) {
 		    di->maxcols = b->arr[LEFT].tlen[i];
@@ -478,7 +488,7 @@ DiffInfo *build_diff_info (char *prog, c
 	;
 
     if (lines > 0) {
-	b = (Block *) calloc (1, sizeof (Block));
+	b = (Block *) xcalloc (1, sizeof (Block));
 	b->selected = NEITHER;
 	b->arr[LEFT].type = b->arr[RIGHT].type = SAME;
 	b->sline = sline;
@@ -487,11 +497,11 @@ DiffInfo *build_diff_info (char *prog, c
 	b->arr[LEFT].fsize = b->arr[RIGHT].fsize = lines;
 	b->ssize = lines;
 		
-	b->arr[LEFT].text = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-	b->arr[LEFT].wtext = (char **) calloc (b->arr[LEFT].fsize, sizeof (char *));
-	b->arr[LEFT].tlen = (short *) calloc (b->arr[LEFT].fsize, sizeof (short));
+	b->arr[LEFT].text = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+	b->arr[LEFT].wtext = (char **) xcalloc (b->arr[LEFT].fsize, sizeof (char *));
+	b->arr[LEFT].tlen = (short *) xcalloc (b->arr[LEFT].fsize, sizeof (short));
  	for (i = 0; i < b->arr[LEFT].fsize; i++) {
-	    getline (file2, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
+	    get_line (file2, &b->arr[LEFT].text[i], &b->arr[LEFT].wtext[i]);
 	    b->arr[LEFT].tlen[i] = strlen (b->arr[LEFT].text[i]);
 	    if (di->maxcols < b->arr[LEFT].tlen[i]) {
 		di->maxcols = b->arr[LEFT].tlen[i];
@@ -522,21 +532,23 @@ DiffInfo *build_diff_info (char *prog, c
  */
 static char *duplicate (char *s, int *flag)
 {
-    int len, i, tabs, ctrls;
+    int len, i, tabs, ctrls, latin, ch;
 
     /* 
      * compute length of new string, taking tabs and control 
      * characters into account
      */
     for (i = 0, len = 0, ctrls = tabs = 0; s[i] != '\0'; i++) {
-	if (isascii (s[i])) {
+    ch = s [i];
+	latin = islatin(ch);
+	if ((isascii(ch) || latin)) {
 	    if (s[i] == '\t') {
 		tabs++;
 		len += 8;
 		len /= 8;
 		len *= 8;
 	    }
-	    else if (iscntrl (s[i])) {
+	    else if (!latin && iscntrl (s[i])) {
 		ctrls++;
 		len += 2;
 	    }
@@ -550,17 +562,19 @@ static char *duplicate (char *s, int *fl
     }
 
     if (tabs || ctrls) {
-	char *ret = (char *) calloc (1, len + 1);
-	int j;
+	char *ret = (char *) xcalloc (1, len + 1);
+	int j, ch;
 
 	for (i = 0, j = 0; s[i] != '\0'; i++) {
-	    if (isascii (s[i])) {
+	    ch = s[i];
+	    latin = islatin(ch);
+	    if ((isascii(ch) || latin)) {
 		if (s[i] == '\t') {
 		    ret[j++] = ' ';
 		    while ((j % 8) != 0)
 			ret[j++] = ' ';
 		}
-		else if (iscntrl (s[i])) {
+		else if (!latin && iscntrl (s[i])) {
 		    ret[j++] = '^';
 		    ret[j++] = (s[i] + '@') & 0x7f;
 		}
@@ -585,7 +599,7 @@ static char *duplicate (char *s, int *fl
     }
     else {
 	*flag = False;
-	return (strdup (s));
+	return (xstrdup (s));
     }
 }
 
@@ -663,7 +677,7 @@ static int eatline (FILE *f)
  * printable) if necessary.  Silently truncate input lines at BUFSIZ
  * characters.
  */
-static void getline (FILE *f, char **cooked, char **raw)
+static void get_line (FILE *f, char **cooked, char **raw)
 {
     char buffer[BUFSIZ+1];
     char *s;
@@ -685,7 +699,7 @@ static void getline (FILE *f, char **coo
 	while (getc (f) != '\n')
 	    ;
     *cooked = s;
-    *raw = (flag) ? strdup (buffer) : NULL;
+    *raw = (flag) ? xstrdup (buffer) : NULL;
 }
 
 /* 
