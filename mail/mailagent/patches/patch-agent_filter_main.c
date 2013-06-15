$NetBSD: patch-agent_filter_main.c,v 1.1 2013/06/15 06:09:37 obache Exp $

--- agent/filter/main.c.orig	2001-03-17 18:31:21.000000000 +0000
+++ agent/filter/main.c
@@ -56,6 +56,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <signal.h>
 #include <sys/types.h>
 #include <errno.h>
@@ -81,7 +82,7 @@ extern void env_home();		/* Only for tes
 extern int errno;
 
 
-public void main(argc, argv, envp)
+public int main(argc, argv, envp)
 int argc;
 char **argv;
 char **envp;
