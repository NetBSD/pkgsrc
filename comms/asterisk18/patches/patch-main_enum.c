$NetBSD: patch-main_enum.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/enum.c.orig	2021-03-04 16:46:08.000000000 +0000
+++ main/enum.c
@@ -219,7 +219,7 @@ static int blr_txt(const char *cc, const
 	ast_mutex_unlock(&enumlock);
 
 	for (p2 = (char *) cc + strlen(cc) - 1; p2 >= cc; p2--) {
-		if (isdigit(*p2)) {
+		if (isdigit((unsigned char)*p2)) {
 			*p1++ = *p2;
 			*p1++ = '.';
 		}
@@ -348,7 +348,7 @@ static int blr_ebl(const char *cc, const
 	ast_mutex_unlock(&enumlock);
 
 	for (p2 = (char *) cc + strlen(cc) - 1; p2 >= cc; p2--) {
-		if (isdigit(*p2)) {
+		if (isdigit((unsigned char)*p2)) {
 			*p1++ = *p2;
 			*p1++ = '.';
 		}
@@ -458,7 +458,7 @@ static int parse_naptr(unsigned char *ds
 		naptrinput, flags, services, regexp, repl);
 
 
-	if (tolower(flags[0]) != 'u') {
+	if (tolower((unsigned char)flags[0]) != 'u') {
 		ast_log(LOG_WARNING, "NAPTR Flag must be 'U' or 'u'.\n");
 		return -1;
 	}
@@ -551,7 +551,7 @@ static int parse_naptr(unsigned char *ds
 	 * beginning and ending indexes of the substring to insert as the backreference.
 	 * if no backreference is found, continue copying the subst into tempdst */
 	while (*subst && (d_len > 0)) {
-		if ((subst[0] == '\\') && isdigit(subst[1])) { /* is this character the beginning of a backreference */
+		if ((subst[0] == '\\') && isdigit((unsigned char)subst[1])) { /* is this character the beginning of a backreference */
 			matchindex = (int) (subst[1] - '0');
 			if (matchindex >= ARRAY_LEN(pmatch)) {
 				ast_log(LOG_WARNING, "Error during regex substitution. Invalid pmatch index.\n");
@@ -573,7 +573,7 @@ static int parse_naptr(unsigned char *ds
 				ast_log(LOG_WARNING, "Error during regex substitution. Invalid backreference index.\n");
 				return -1;
 			}
-		} else if (isprint(*subst)) {
+		} else if (isprint((unsigned char)*subst)) {
 			*d++ = *subst++;
 			d_len--;
 		} else {
@@ -830,7 +830,7 @@ int ast_get_enum(struct ast_channel *cha
 
 		p1 = middle + strlen(middle);
 		for (p2 = (char *) number + sdl - 1; p2 >= number; p2--) {
-			if (isdigit(*p2)) {
+			if (isdigit((unsigned char)*p2)) {
 				*p1++ = *p2;
 				*p1++ = '.';
 			}
@@ -849,7 +849,7 @@ int ast_get_enum(struct ast_channel *cha
 	/* flip left into domain */
 	p1 = domain;
 	for (p2 = left + strlen(left); p2 >= left; p2--) {
-		if (isdigit(*p2)) {
+		if (isdigit((unsigned char)*p2)) {
 			*p1++ = *p2;
 			*p1++ = '.';
 		}
@@ -973,7 +973,7 @@ static char *format_numeric_domain(const
 
 	if (buffer) {
 		while (src >= number) {
-			if (isdigit(*src)) {
+			if (isdigit((unsigned char)*src)) {
 				*dst++ = *src;
 				*dst++ = '.';
 			}
