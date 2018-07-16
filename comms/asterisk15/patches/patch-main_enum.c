$NetBSD: patch-main_enum.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- main/enum.c.orig	2018-05-07 17:27:38.736672469 +0000
+++ main/enum.c
@@ -218,7 +218,7 @@ static int blr_txt(const char *cc, const
 	ast_mutex_unlock(&enumlock);
 
 	for (p2 = (char *) cc + strlen(cc) - 1; p2 >= cc; p2--) {
-		if (isdigit(*p2)) {
+		if (isdigit((unsigned char)*p2)) {
 			*p1++ = *p2;
 			*p1++ = '.';
 		}
@@ -347,7 +347,7 @@ static int blr_ebl(const char *cc, const
 	ast_mutex_unlock(&enumlock);
 
 	for (p2 = (char *) cc + strlen(cc) - 1; p2 >= cc; p2--) {
-		if (isdigit(*p2)) {
+		if (isdigit((unsigned char)*p2)) {
 			*p1++ = *p2;
 			*p1++ = '.';
 		}
@@ -456,7 +456,7 @@ static int parse_naptr(unsigned char *ds
 		naptrinput, flags, services, regexp, repl);
 
 
-	if (tolower(flags[0]) != 'u') {
+	if (tolower((unsigned char)flags[0]) != 'u') {
 		ast_log(LOG_WARNING, "NAPTR Flag must be 'U' or 'u'.\n");
 		return -1;
 	}
@@ -539,7 +539,7 @@ static int parse_naptr(unsigned char *ds
 	 * beginning and ending indexes of the substring to insert as the backreference.
 	 * if no backreference is found, continue copying the subst into tempdst */
 	while (*subst && (d_len > 0)) {
-		if ((subst[0] == '\\') && isdigit(subst[1])) { /* is this character the beginning of a backreference */
+		if ((subst[0] == '\\') && isdigit((unsigned char)subst[1])) { /* is this character the beginning of a backreference */
 			matchindex = (int) (subst[1] - '0');
 			if (matchindex >= ARRAY_LEN(pmatch)) {
 				ast_log(LOG_WARNING, "Error during regex substitution. Invalid pmatch index.\n");
@@ -561,7 +561,7 @@ static int parse_naptr(unsigned char *ds
 				ast_log(LOG_WARNING, "Error during regex substitution. Invalid backreference index.\n");
 				return -1;
 			}
-		} else if (isprint(*subst)) {
+		} else if (isprint((unsigned char)*subst)) {
 			*d++ = *subst++;
 			d_len--;
 		} else {
@@ -818,7 +818,7 @@ int ast_get_enum(struct ast_channel *cha
 
 		p1 = middle + strlen(middle);
 		for (p2 = (char *) number + sdl - 1; p2 >= number; p2--) {
-			if (isdigit(*p2)) {
+			if (isdigit((unsigned char)*p2)) {
 				*p1++ = *p2;
 				*p1++ = '.';
 			}
@@ -837,7 +837,7 @@ int ast_get_enum(struct ast_channel *cha
 	/* flip left into domain */
 	p1 = domain;
 	for (p2 = left + strlen(left); p2 >= left; p2--) {
-		if (isdigit(*p2)) {
+		if (isdigit((unsigned char)*p2)) {
 			*p1++ = *p2;
 			*p1++ = '.';
 		}
@@ -949,7 +949,7 @@ int ast_get_txt(struct ast_channel *chan
 	}
 
 	while (pos >= 0) {
-		if (isdigit(number[pos])) {
+		if (isdigit((unsigned char)number[pos])) {
 			tmp[newpos++] = number[pos];
 			tmp[newpos++] = '.';
 		}
