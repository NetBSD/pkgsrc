$NetBSD: patch-sslh-main.c,v 1.4 2016/08/07 13:19:24 nils Exp $

* getopt_long_only does not exist on NetBSD getopt.

--- sslh-main.c.orig	2016-03-29 19:19:05.000000000 +0000
+++ sslh-main.c
@@ -443,7 +443,7 @@ static void cmdline_config(int argc, cha
 #ifdef LIBCONFIG
     optind = 1;
     opterr = 0; /* we're missing protocol options at this stage so don't output errors */
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 'v') {
             verbose++;
         }
@@ -480,7 +480,7 @@ static void parse_cmdline(int argc, char
     optind = 1;
     opterr = 1;
 next_arg:
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 0) continue;
 
         if (c >= PROT_SHIFT) {
