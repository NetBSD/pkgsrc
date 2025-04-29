$NetBSD: patch-shell__cmd.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

--- shell_cmd.c.orig	1994-12-28 16:42:44.000000000 +0000
+++ shell_cmd.c
@@ -16,12 +16,15 @@ static char sccsid[] = "@(#) shell_cmd.c
 
 #include <sys/types.h>
 #include <sys/param.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <unistd.h>
+#include <fcntl.h>
 
-extern void exit();
+#include <stdlib.h>
 
 /* Local stuff. */
 
@@ -29,7 +32,7 @@ extern void exit();
 
 /* Forward declarations. */
 
-static void do_child();
+static void do_child(char *);
 
 /* shell_cmd - execute shell command */
 
