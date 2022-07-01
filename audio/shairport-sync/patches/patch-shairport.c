$NetBSD: patch-shairport.c,v 1.1 2022/07/01 18:36:28 nia Exp $

Show the configurable config file install location.

--- shairport.c.orig	2021-12-08 10:42:01.000000000 +0000
+++ shairport.c
@@ -217,11 +217,11 @@ void usage(char *progname) {
 #endif
   printf("    -V, --version           show version information.\n");
   printf("    -c, --configfile=FILE   read configuration settings from FILE. Default is "
-         "/etc/shairport-sync.conf.\n");
+         "@PKG_SYSCONFDIR@/shairport-sync.conf.\n");
 
   printf("\n");
   printf("The following general options are for backward compatibility. These and all new options "
-         "have settings in the configuration file, by default /etc/shairport-sync.conf:\n");
+         "have settings in the configuration file, by default @PKG_SYSCONFDIR@/shairport-sync.conf:\n");
   printf("    -v, --verbose           -v print debug information; -vv more; -vvv lots.\n");
   printf("    -p, --port=PORT         set RTSP listening port.\n");
   printf("    -a, --name=NAME         set advertised name.\n");
@@ -1279,7 +1279,7 @@ int parse_options(int argc, char **argv)
 #ifdef DEFINED_CUSTOM_PID_DIR
   char *use_this_pid_dir = PIDDIR;
 #else
-  char *use_this_pid_dir = "/var/run/shairport-sync";
+  char *use_this_pid_dir = "@VARBASE@/run/shairport-sync";
 #endif
   // debug(1,"config.piddir \"%s\".",config.piddir);
   if (config.piddir)
