$NetBSD: patch-sslh-main.c,v 1.2 2014/11/28 10:45:28 bsiegert Exp $

* getopt_long_only does not exist on NetBSD getopt.

--- sslh-main.c.orig	2014-02-11 21:06:01.000000000 +0000
+++ sslh-main.c
@@ -358,7 +358,7 @@ static void cmdline_config(int argc, cha
 #ifdef LIBCONFIG
     optind = 1;
     opterr = 0; /* we're missing protocol options at this stage so don't output errors */
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 'F') {
             config_filename = optarg;
             /* find the end of the listen list */
@@ -383,7 +383,7 @@ static void parse_cmdline(int argc, char
     optind = 1;
     opterr = 1;
 next_arg:
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 0) continue;
 
         if (c >= PROT_SHIFT) {
