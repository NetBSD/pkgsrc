$NetBSD: patch-plugins_check_nagios.c,v 1.2 2022/04/02 10:35:35 nia Exp $

Crash fix: initialize variable, check bounds on string copy.

--- plugins/check_nagios.c.orig	2017-01-19 16:01:31.000000000 +0000
+++ plugins/check_nagios.c
@@ -72,7 +72,7 @@ main (int argc, char **argv)
 #ifdef PS_USES_PROCETIME
 	char procetime[MAX_INPUT_BUFFER];
 #endif /* PS_USES_PROCETIME */
-	char procprog[MAX_INPUT_BUFFER];
+	char procprog[MAX_INPUT_BUFFER] = { '\0' };
 	char *procargs;
 	int pos, cols;
 	int expected_cols = PS_COLS - 1;
@@ -144,7 +144,8 @@ main (int argc, char **argv)
 			/* Some ps return full pathname for command. This removes path */
 			temp_string = strtok ((char *)procprog, "/");
 			while (temp_string) {
-				strcpy(procprog, temp_string);
+				strncpy(procprog, temp_string, sizeof(procprog));
+				procprog[sizeof(procprog) - 1] = '\0';
 				temp_string = strtok (NULL, "/");
 			}
 
