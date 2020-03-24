$NetBSD: patch-common_string-utils.c,v 1.1 2020/03/24 06:29:40 rillig Exp $

string-utils.c:147:7: error: array subscript has type 'char' [-Werror=char-subscripts]
(and a few others)

https://savannah.nongnu.org/bugs/index.php?58033

--- common/string-utils.c.orig	2012-05-03 23:14:50.000000000 +0000
+++ common/string-utils.c
@@ -30,6 +30,10 @@
 #include "error.h"		/* common */
 #include "string-utils.h"	/* common */
 
+static int is_alnum(unsigned char ch) { return isalnum(ch); }
+static int is_space(unsigned char ch) { return isspace(ch); }
+static int to_lower(unsigned char ch) { return tolower(ch); }
+
 /**
  * Return a zero-based of a character in a string.
  */
@@ -144,7 +148,7 @@ ends_with_nocase(const char *str, const 
 		return false;
 
 	for (c = 0; end[c] != '\0'; c++) {
-		if (tolower(end[c]) != tolower(str[c+diff]))
+		if (to_lower(end[c]) != to_lower(str[c+diff]))
 			return false;
 	}
 
@@ -184,7 +188,7 @@ starts_with_nocase(const char *str, cons
 {
 	int c;
 	for (c = 0; str[c] != '\0'; c++) {
-		if (tolower(str[c]) != tolower(start[c]))
+		if (to_lower(str[c]) != to_lower(start[c]))
 			break;
 	}
 	return (start[c] == '\0');
@@ -230,7 +234,7 @@ str_convert(char *str, int (*convert)(in
 int
 iswordchar(int ch)
 {
-	return isalnum(ch) || ch == '_';
+	return is_alnum(ch) || ch == '_';
 }
 
 /**
@@ -398,10 +402,10 @@ word_get_index(const char *str, int pos)
 	int c;
 
 	for (c = 0; str[c] != '\0' && c < pos; c++) {
-		if (!in_word && !isspace(str[c])) {
+		if (!in_word && !is_space(str[c])) {
 			in_word = true;
 		}
-		if (in_word && isspace(str[c])) {
+		if (in_word && is_space(str[c])) {
 			in_word = false;
 			words++;
 		}
@@ -419,12 +423,12 @@ word_get(const char *str, int idx)
 	int c;
 
 	for (c = 0; str[c] != '\0'; c++) {
-		if (!in_word && !isspace(str[c])) {
+		if (!in_word && !is_space(str[c])) {
 			words++;
 			start = c;
 			in_word = true;
 		}
-		if (in_word && isspace(str[c])) {
+		if (in_word && is_space(str[c])) {
 			if (words > idx)
 				return substring(str, start, c);
 			in_word = false;
