$NetBSD: patch-admin.c,v 1.1 2026/05/19 18:38:10 spz Exp $

deal with ctype functions faulting on invalid input on NetBSD 11

--- admin.c.orig	2026-05-16 21:15:52.974631909 +0000
+++ admin.c
@@ -10,7 +10,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <string.h>
-#include <ctype.h>
+#include "ctypeconv.h"
 #include "config.h"
 #include "global.h"
 #include "admin.h"
@@ -95,8 +95,8 @@ get_cmd(char *prompt1, char *prompt2)
 	} while (c == '!');
     }
 
-    if (islower(c))
-	c = toupper(c);
+    if (ISLOWER(c))
+	c = TOUPPER(c);
 
     return c;
 }
@@ -711,7 +711,7 @@ master_admin(void)
 		value = get_entry("Option value", 1L, 10000L);
 		if (value < 0)
 		    break;
-		send_master(SM_SET_OPTION, (group_header *) NULL, tolower(c), value);
+		send_master(SM_SET_OPTION, (group_header *) NULL, TOLOWER(c), value);
 		break;
 
 	    case 'S':
@@ -784,10 +784,10 @@ tr_failed:
 	goto loop;
     }
 log_tail:
-    if (c == '$' || c == SP || isdigit(c)) {
+    if (c == '$' || c == SP || ISDIGIT(c)) {
 	int             n;
 
-	n = isdigit(c) ? 10 * (c - '0') : 10;
+	n = ISDIGIT(c) ? 10 * (c - '0') : 10;
 	sprintf(command, "tail -%d %s", n, log_file);
 	system(command);
 	goto loop;
