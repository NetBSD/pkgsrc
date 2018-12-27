$NetBSD: patch-mmpfb_main.cc,v 1.1 2018/12/27 15:16:53 joerg Exp $

--- mmpfb/main.cc.orig	2003-01-05 22:33:51.000000000 +0000
+++ mmpfb/main.cc
@@ -153,13 +153,15 @@ do_file(const char *filename, PsresDatab
   if (!f) {
     // check for PostScript or instance name
     Filename fn = psres->filename_value("FontOutline", filename);
-    char *underscore = strchr(filename, '_');
+    const char *underscore = strchr(filename, '_');
     if (!fn && underscore) {
       fn = psres->filename_value
 	("FontOutline", PermString(filename, underscore - filename));
       int i = 0;
       while (underscore[0] == '_' && underscore[1]) {
-	double x = strtod(underscore + 1, &underscore);
+        char *underscore2;
+	double x = strtod(underscore + 1, &underscore2);
+	underscore = underscore2;
 	set_design(i, x);
 	i++;
       }
