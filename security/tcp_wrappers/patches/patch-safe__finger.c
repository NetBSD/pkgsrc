$NetBSD: patch-safe__finger.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

--- safe_finger.c.orig	1994-12-28 16:42:42.000000000 +0000
+++ safe_finger.c
@@ -22,12 +22,16 @@ static char sccsid[] = "@(#) safe_finger
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <pwd.h>
+#include <unistd.h>
+#include <fcntl.h>
+#include <stdlib.h>
 
-extern void exit();
+int pipe_stdin(char**);
 
 /* Local stuff */
 
@@ -49,6 +53,7 @@ int     sig;
     exit(0);
 }
 
+int
 main(argc, argv)
 int     argc;
 char  **argv;
