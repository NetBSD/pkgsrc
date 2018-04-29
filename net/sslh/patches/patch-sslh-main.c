$NetBSD: patch-sslh-main.c,v 1.6 2018/04/29 09:41:16 wiz Exp $

* getopt_long_only does not exist on NetBSD getopt.
* Support documented command line options.

--- sslh-main.c.orig	2018-02-11 17:42:21.000000000 +0000
+++ sslh-main.c
@@ -80,7 +80,7 @@ static struct option const_options[] = {
 };
 static struct option* all_options;
 static struct proto* builtins;
-static const char *optstr = "vt:T:p:VP:C:F::";
+static const char *optstr = "finvt:T:p:VP:C:F::";
 
 
 
@@ -460,7 +460,7 @@ static void cmdline_config(int argc, cha
 #ifdef LIBCONFIG
     optind = 1;
     opterr = 0; /* we're missing protocol options at this stage so don't output errors */
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 'v') {
             verbose++;
         }
@@ -497,7 +497,7 @@ static void parse_cmdline(int argc, char
     optind = 1;
     opterr = 1;
 next_arg:
-    while ((c = getopt_long_only(argc, argv, optstr, all_options, NULL)) != -1) {
+    while ((c = getopt_long(argc, argv, optstr, all_options, NULL)) != -1) {
         if (c == 0) continue;
 
         if (c >= PROT_SHIFT) {
@@ -527,6 +527,18 @@ next_arg:
 
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
