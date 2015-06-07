$NetBSD: patch-lib_libpam_openpam__readword.c,v 1.1 2015/06/07 22:46:08 joerg Exp $

--- lib/libpam/openpam_readword.c.orig	2015-06-05 20:50:30.000000000 +0000
+++ lib/libpam/openpam_readword.c
@@ -55,18 +55,35 @@ openpam_readword(FILE *f, int *lineno, s
 {
 	char *word;
 	size_t size, len;
-	int ch, comment, escape, quote;
+	int ch, escape, quote;
 	int serrno;
 
 	errno = 0;
 
 	/* skip initial whitespace */
-	comment = 0;
-	while ((ch = getc(f)) != EOF && ch != '\n') {
-		if (ch == '#')
-			comment = 1;
-		if (!is_lws(ch) && !comment)
+	escape = quote = 0;
+	while ((ch = getc(f)) != EOF) {
+		if (ch == '\n') {
+			/* either EOL or line continuation */
+			if (!escape)
+				break;
+			if (lineno != NULL)
+				++*lineno;
+			escape = 0;
+		} else if (escape) {
+			/* escaped something else */
+			break;
+		} else if (ch == '#') {
+			/* comment: until EOL, no continuation */
+			while ((ch = getc(f)) != EOF)
+				if (ch == '\n')
+					break;
 			break;
+		} else if (ch == '\\') {
+			escape = 1;
+		} else if (!is_ws(ch)) {
+			break;
+		}
 	}
 	if (ch == EOF)
 		return (NULL);
@@ -76,7 +93,6 @@ openpam_readword(FILE *f, int *lineno, s
 
 	word = NULL;
 	size = len = 0;
-	escape = quote = 0;
 	while ((ch = fgetc(f)) != EOF && (!is_ws(ch) || quote || escape)) {
 		if (ch == '\\' && !escape && quote != '\'') {
 			/* escape next character */
@@ -90,7 +106,7 @@ openpam_readword(FILE *f, int *lineno, s
 		} else if (ch == quote && !escape) {
 			/* end quote */
 			quote = 0;
-		} else if (ch == '\n' && escape && quote != '\'') {
+		} else if (ch == '\n' && escape) {
 			/* line continuation */
 			escape = 0;
 		} else {
