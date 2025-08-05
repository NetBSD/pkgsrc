$NetBSD: patch-shairport.c,v 1.2 2025/08/05 19:33:02 schmonz Exp $

Show the configurable config file install location.

--- shairport.c.orig	2025-01-31 14:57:31.000000000 +0000
+++ shairport.c
@@ -1536,7 +1536,7 @@ int parse_options(int argc, char **argv)
   char *use_this_pid_dir = PIDDIR;
 #else
   char temp_pid_dir[4096];
-  strcpy(temp_pid_dir, "/var/run/");
+  strcpy(temp_pid_dir, "@VARBASE@/run/");
   strcat(temp_pid_dir, config.appName);
   debug(3, "Default PID directory is \"%s\".", temp_pid_dir);
   char *use_this_pid_dir = temp_pid_dir;
