$NetBSD: patch-mmafm_main.cc,v 1.1 2018/12/27 15:16:53 joerg Exp $

--- mmafm/main.cc.orig	2018-12-25 23:20:24.379803504 +0000
+++ mmafm/main.cc
@@ -157,7 +157,7 @@ read_file(const char *fn, MetricsFinder 
       return;
     
     // check for instance name. don't use InstanceMetricsFinder.
-    char *underscore = strchr(fn, '_');
+    const char *underscore = strchr(fn, '_');
     if (underscore)
       new_amfm = finder->find_amfm(PermString(fn, underscore - fn), errh);
     if (!new_amfm)
@@ -166,7 +166,9 @@ read_file(const char *fn, MetricsFinder 
     
     int i = 0;
     while (underscore[0] == '_' && underscore[1]) {
-      double x = strtod(underscore + 1, &underscore);
+      char *underscore2;
+      double x = strtod(underscore + 1, &underscore2);
+      underscore = underscore2;
       set_design(i, x);
       i++;
     }
@@ -249,7 +251,7 @@ main(int argc, char **argv)
 
   errh = new FileErrorHandler(stderr);
   
-  char *output_name = "<stdout>";
+  const char *output_name = "<stdout>";
   FILE *output_file = 0;
   int precision = 3;
   double kern_precision = 2.0;
