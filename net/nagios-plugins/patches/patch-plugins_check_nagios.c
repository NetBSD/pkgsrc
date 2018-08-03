$NetBSD: patch-plugins_check_nagios.c,v 1.1 2018/08/03 14:03:09 manu Exp $

Crash fix: initialize variable, check bounds on string copy.

--- plugins/check_nagios.c.orig
+++ plugins/check_nagios.c
@@ -71,9 +71,9 @@
 	char procstat[8];
 #ifdef PS_USES_PROCETIME
 	char procetime[MAX_INPUT_BUFFER];
 #endif /* PS_USES_PROCETIME */
-	char procprog[MAX_INPUT_BUFFER];
+	char procprog[MAX_INPUT_BUFFER] = { '\0' };
 	char *procargs;
 	int pos, cols;
 	int expected_cols = PS_COLS - 1;
 	const char *zombie = "Z";
@@ -143,9 +143,10 @@
 
 			/* Some ps return full pathname for command. This removes path */
 			temp_string = strtok ((char *)procprog, "/");
 			while (temp_string) {
-				strcpy(procprog, temp_string);
+				strncpy(procprog, temp_string, sizeof(procprog));
+				procprog[sizeof(procprog) - 1] = '\0';
 				temp_string = strtok (NULL, "/");
 			}
 
 			/* May get empty procargs */
