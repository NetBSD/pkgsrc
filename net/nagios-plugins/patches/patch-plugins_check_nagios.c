$NetBSD: patch-plugins_check_nagios.c,v 1.3 2023/01/09 00:28:41 sekiya Exp $

Crash fix: initialize variable, check bounds on string copy.

--- plugins/check_nagios.c.orig	2019-12-05 06:53:08.000000000 +0900
+++ plugins/check_nagios.c	2023-01-09 08:53:37.895632188 +0900
@@ -73,7 +73,7 @@
 #ifdef PS_USES_PROCETIME
 	char procetime[MAX_INPUT_BUFFER];
 #endif /* PS_USES_PROCETIME */
-	char procprog[MAX_INPUT_BUFFER];
+	char procprog[MAX_INPUT_BUFFER] = { '\0' };
 	char *procargs;
 	int pos, cols;
 	int expected_cols = PS_COLS - 1;
@@ -145,7 +145,8 @@
 			/* Some ps return full pathname for command. This removes path */
 			temp_string = strtok ((char *)procprog, "/");
 			while (temp_string) {
-				strcpy(procprog, temp_string);
+				strncpy(procprog, temp_string, sizeof(procprog));
+				procprog[sizeof(procprog) - 1] = '\0';
 				temp_string = strtok (NULL, "/");
 			}
 
