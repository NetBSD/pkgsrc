$NetBSD: patch-src_main.c,v 1.1 2026/02/13 15:09:13 nia Exp $

Trick elkulator into not loading files from its executable
directory.

--- src/main.c.orig	2026-02-13 13:47:19.571347885 +0000
+++ src/main.c
@@ -66,8 +66,15 @@ void initelk(int argc, char *argv[])
 {
         int c;
         char *p;
+        char *home = getenv("HOME");
         int tapenext=0,discnext=0;
-        get_executable_name(exedir,511);
+
+        if (home == NULL)
+        {
+                home = "/";
+        }
+        snprintf(exedir, 511, "%s/.elkulator/foobar", home);
+
         p=get_filename(exedir);
         p[0]=0;
         discname[0]=discname2[0]=tapename[0]=0;
