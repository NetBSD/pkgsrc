$NetBSD: patch-sslh-main.c,v 1.5 2017/08/15 14:23:50 jperkin Exp $

* getopt_long_only does not exist on NetBSD getopt.
* Support documented command line options.

--- sslh-main.c.orig	2016-03-29 19:19:05.000000000 +0000
+++ sslh-main.c
@@ -78,7 +78,7 @@ static struct option const_options[] = {
 };
 static struct option* all_options;
 static struct proto* builtins;
-static const char *optstr = "vt:T:p:VP:F::";
+static const char *optstr = "finvt:T:p:VP:F::";
 
 
 
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
@@ -510,6 +510,18 @@ next_arg:
 
         switch (c) {
 
+        case 'f':
+            foreground = 1;
+            break;
+
+        case 'i':
+            inetd = 1;
+            break;
+
+        case 'n':
+            numeric = 1;
+            break;
+
         case 'F':
             /* Legal option, but do nothing, it was already processed in
              * cmdline_config() */
