$NetBSD: patch-main_asterisk.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/asterisk.c.orig	2019-09-05 13:09:20.000000000 +0000
+++ main/asterisk.c
@@ -852,7 +852,7 @@ int64_t ast_mark(int i, int startstop)
 #define DEFINE_PROFILE_MIN_MAX_VALUES min = 0; \
 	max = prof_data->entries;\
 	if  (a->argc > 3) { /* specific entries */ \
-		if (isdigit(a->argv[3][0])) { \
+		if (isdigit((unsigned char)a->argv[3][0])) { \
 			min = atoi(a->argv[3]); \
 			if (a->argc == 5 && strcmp(a->argv[4], "-")) \
 				max = atoi(a->argv[4]); \
@@ -2274,7 +2274,7 @@ static int remoteconsolehandler(const ch
 	if (!ast_all_zeros(s))
 		ast_el_add_history(s);
 
-	while (isspace(*s)) {
+	while (isspace((unsigned char)*s)) {
 		s++;
 	}
 
@@ -2286,7 +2286,7 @@ static int remoteconsolehandler(const ch
 			ast_safe_system(getenv("SHELL") ? getenv("SHELL") : "/bin/sh");
 		ret = 1;
 	} else if ((strncasecmp(s, "quit", 4) == 0 || strncasecmp(s, "exit", 4) == 0) &&
-	    (s[4] == '\0' || isspace(s[4]))) {
+	    (s[4] == '\0' || isspace((unsigned char)s[4]))) {
 		quit_handler(0, SHUTDOWN_FAST, 0);
 		ret = 1;
 	}
@@ -2949,7 +2949,7 @@ static char *cli_complete(EditLine *edit
 	ptr = (char *)lf->cursor;
 	if (ptr) {
 		while (ptr > lf->buffer) {
-			if (isspace(*ptr)) {
+			if (isspace((unsigned char)*ptr)) {
 				ptr++;
 				break;
 			}
