$NetBSD: patch-sslh-main.c,v 1.3 2015/04/19 19:02:35 wiz Exp $

* getopt_long_only does not exist on NetBSD getopt.

--- sslh-main.c.orig	2015-03-09 20:51:39.000000000 +0000
+++ sslh-main.c
@@ -362,7 +362,7 @@ static void cmdline_config(int argc, cha
 #ifdef LIBCONFIG
     optind = 1;
     opterr = 0; /* we're missing protocol options at this stage so don't output errors */
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 'F') {
             config_filename = optarg;
             if (config_filename) {
@@ -397,7 +397,7 @@ static void parse_cmdline(int argc, char
     optind = 1;
     opterr = 1;
 next_arg:
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 0) continue;
 
         if (c >= PROT_SHIFT) {
