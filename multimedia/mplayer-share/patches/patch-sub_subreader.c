$NetBSD: patch-sub_subreader.c,v 1.2 2012/06/11 21:55:34 wiz Exp $

Call isspace(3) with unsigned char, instead of char, to handle
non-ASCII characters properly.

--- sub/subreader.c.orig	2012-05-21 19:17:55.000000000 +0000
+++ sub/subreader.c
@@ -94,10 +94,10 @@ static int eol(char p) {
 /* Remove leading and trailing space */
 static void trail_space(char *s) {
 	int i = 0;
-	while (isspace(s[i])) ++i;
+	while (isspace((unsigned char)s[i])) ++i;
 	if (i) strcpy(s, s + i);
 	i = strlen(s) - 1;
-	while (i > 0 && isspace(s[i])) s[i--] = '\0';
+	while (i > 0 && isspace((unsigned char)s[i])) s[i--] = '\0';
 }
 
 static char *stristr(const char *haystack, const char *needle) {
@@ -742,7 +742,7 @@ static subtitle *sub_read_line_pjs(strea
     if (!stream_read_line (st, line, LINE_LEN, utf16))
 	return NULL;
     /* skip spaces */
-    for (s=line; *s && isspace(*s); s++);
+    for (s=line; *s && isspace((unsigned char)*s); s++);
     /* allow empty lines at the end of the file */
     if (*s==0)
 	return NULL;
@@ -795,7 +795,7 @@ static subtitle *sub_read_line_mpsub(str
 			else return current;
 		}
 		p=line;
-		while (isspace(*p)) p++;
+		while (isspace((unsigned char)*p)) p++;
 		if (eol(*p) && num > 0) return current;
 		if (eol(*p)) return NULL;
 
@@ -1830,18 +1830,18 @@ char * strreplace( char * in,char * what
 static void strcpy_trim(char *d, const char *s)
 {
     // skip leading whitespace
-    while (*s && isspace(*s)) {
+    while (*s && isspace((unsigned char)*s)) {
 	s++;
     }
     for (;;) {
 	// copy word
-	while (*s && !isspace(*s)) {
+	while (*s && !isspace((unsigned char)*s)) {
 	    *d = tolower(*s);
 	    s++; d++;
 	}
 	if (*s == 0) break;
 	// trim excess whitespace
-	while (*s && isspace(*s)) {
+	while (*s && isspace((unsigned char)*s)) {
 	    s++;
 	}
 	if (*s == 0) break;
@@ -1885,7 +1885,7 @@ static void strcpy_get_ext(char *d, cons
 static int whiteonly(const char *s)
 {
     while (*s) {
-	if (!isspace(*s)) return 0;
+	if (!isspace((unsigned char)*s)) return 0;
 	s++;
   }
     return 1;
