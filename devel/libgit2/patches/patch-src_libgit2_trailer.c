$NetBSD: patch-src_libgit2_trailer.c,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure proper value range for args to ctype functions.

--- src/libgit2/trailer.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/libgit2/trailer.c
@@ -24,7 +24,7 @@ static const char *const git_generated_p
 static int is_blank_line(const char *str)
 {
 	const char *s = str;
-	while (*s && *s != '\n' && isspace(*s))
+	while (*s && *s != '\n' && isspace((unsigned char)*s))
 		s++;
 	return !*s || *s == '\n';
 }
@@ -93,7 +93,7 @@ static bool find_separator(size_t *out, 
 			return true;
 		}
 
-		if (!whitespace_found && (isalnum(*c) || *c == '-'))
+		if (!whitespace_found && (isalnum((unsigned char)*c) || *c == '-'))
 			continue;
 		if (c != line && (*c == ' ' || *c == '\t')) {
 			whitespace_found = 1;
@@ -233,12 +233,12 @@ static size_t find_trailer_start(const c
 		}
 
 		find_separator(&separator_pos, bol, TRAILER_SEPARATORS);
-		if (separator_pos >= 1 && !isspace(bol[0])) {
+		if (separator_pos >= 1 && !isspace((unsigned char)bol[0])) {
 			trailer_lines++;
 			possible_continuation_lines = 0;
 			if (recognized_prefix)
 				continue;
-		} else if (isspace(bol[0]))
+		} else if (isspace((unsigned char)bol[0]))
 			possible_continuation_lines++;
 		else {
 			non_trailer_lines++;
@@ -323,7 +323,7 @@ int git_message_trailers(git_message_tra
 					goto ret;
 				}
 
-				if (isalnum(*ptr) || *ptr == '-') {
+				if (isalnum((unsigned char)*ptr) || *ptr == '-') {
 					/* legal key character */
 					NEXT(S_KEY);
 				}
