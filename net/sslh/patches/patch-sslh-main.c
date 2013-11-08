$NetBSD: patch-sslh-main.c,v 1.1 2013/11/08 13:33:55 obache Exp $

* getopt_long_only does not exist on NetBSD getopt.

--- sslh-main.c.orig	2013-07-27 14:25:04.000000000 +0000
+++ sslh-main.c
@@ -337,7 +337,7 @@ static void cmdline_config(int argc, cha
 #ifdef LIBCONFIG
     optind = 1;
     opterr = 0; /* we're missing protocol options at this stage so don't output errors */
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 'F') {
             config_filename = optarg;
             /* find the end of the listen list */
@@ -362,7 +362,7 @@ static void parse_cmdline(int argc, char
     optind = 1;
     opterr = 1;
 next_arg:
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 0) continue;
 
         if (c >= PROT_SHIFT) {
