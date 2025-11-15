$NetBSD: patch-sub_subreader.c,v 1.4 2025/11/15 12:43:18 ryoon Exp $

Call isspace(3) with unsigned char, instead of char, to handle
non-ASCII characters properly.

--- sub/subreader.c.orig	2025-01-06 20:56:52.000000000 +0000
+++ sub/subreader.c
@@ -98,10 +98,10 @@ static int eol(char p) {
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
@@ -787,7 +787,7 @@ static subtitle *sub_read_line_pjs(strea
     if (!stream_read_line (st, line, LINE_LEN, utf16))
 	return NULL;
     /* skip spaces */
-    for (s=line; *s && isspace(*s); s++);
+    for (s=line; *s && isspace((unsigned char)*s); s++);
     /* allow empty lines at the end of the file */
     if (*s==0)
 	return NULL;
@@ -840,7 +840,7 @@ static subtitle *sub_read_line_mpsub(str
 			else return current;
 		}
 		p=line;
-		while (isspace(*p)) p++;
+		while (isspace((unsigned char)*p)) p++;
 		if (eol(*p) && num > 0) return current;
 		if (eol(*p)) return NULL;
 
@@ -981,9 +981,9 @@ static subtitle *sub_read_line_jacosub(s
 		    int hours = 0, minutes = 0, seconds, delta, inverter =
 			1;
 		    unsigned units = jacoShift;
-		    switch (toupper(line1[1])) {
+		    switch (toupper((unsigned char)(line1[1]))) {
 		    case 'S':
-			if (isalpha(line1[2])) {
+			if (isalpha((unsigned char)(line1[2]))) {
 			    delta = 6;
 			} else {
 			    delta = 2;
@@ -1018,7 +1018,7 @@ static subtitle *sub_read_line_jacosub(s
 			}
 			break;
 		    case 'T':
-			if (isalpha(line1[2])) {
+			if (isalpha((unsigned char)(line1[2]))) {
 			    delta = 8;
 			} else {
 			    delta = 2;
@@ -1051,15 +1051,15 @@ static subtitle *sub_read_line_jacosub(s
 	while ((*p == ' ') || (*p == '\t')) {
 	    ++p;
 	}
-	if (isalpha(*p)||*p == '[') {
+	if (isalpha((unsigned char)(*p))||*p == '[') {
 	    int cont, jLength;
 
 	    if (sscanf(p, "%s %[^\n\r]", directive, line1) < 2)
 		return (subtitle *) ERR;
 	    jLength = strlen(directive);
 	    for (cont = 0; cont < jLength; ++cont) {
-		if (isalpha(*(directive + cont)))
-		    *(directive + cont) = toupper(*(directive + cont));
+		if (isalpha((unsigned char)(*(directive + cont))))
+		    *(directive + cont) = toupper((unsigned char)(*(directive + cont)));
 	    }
 	    if ((strstr(directive, "RDB") != NULL)
 		|| (strstr(directive, "RDC") != NULL)
@@ -1113,8 +1113,8 @@ static subtitle *sub_read_line_jacosub(s
 		    ++p;
 		    break;
 		}
-		if ((toupper(*(p + 1)) == 'C')
-		    || (toupper(*(p + 1)) == 'F')) {
+		if ((toupper((unsigned char)(*(p + 1))) == 'C')
+		    || (toupper((unsigned char)(*(p + 1))) == 'F')) {
 		    ++p,++p;
 		    break;
 		}
@@ -1886,18 +1886,18 @@ char * strreplace( char * in,char * what
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
-	    *d = tolower(*s);
+	while (*s && !isspace((unsigned char)*s)) {
+	    *d = tolower((unsigned char)(*s));
 	    s++; d++;
 	}
 	if (*s == 0) break;
 	// trim excess whitespace
-	while (*s && isspace(*s)) {
+	while (*s && isspace((unsigned char)*s)) {
 	    s++;
 	}
 	if (*s == 0) break;
@@ -1922,7 +1922,7 @@ static void strcpy_strip_ext_lower(char 
 {
     strcpy_strip_ext(d, s);
     while (*d) {
-	*d = tolower(*d);
+	*d = tolower((unsigned char)(*d));
 	d++;
     }
 }
@@ -1941,7 +1941,7 @@ static void strcpy_get_ext(char *d, cons
 static int whiteonly(const char *s)
 {
     while (*s) {
-	if (!isspace(*s)) return 0;
+	if (!isspace((unsigned char)*s)) return 0;
 	s++;
   }
     return 1;
