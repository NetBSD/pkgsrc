$NetBSD: patch-shell__cmd.c,v 1.1 2024/08/05 12:48:18 tnn Exp $

--- shell_cmd.c.orig	2024-08-05 14:07:12.929804367 +0000
+++ shell_cmd.c
@@ -16,10 +16,13 @@ static char sccsid[] = "@(#) shell_cmd.c
 
 #include <sys/types.h>
 #include <sys/param.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <stdio.h>
 #include <syslog.h>
 #include <string.h>
+#include <unistd.h>
+#include <fcntl.h>
 
 extern void exit();
 
