$NetBSD: patch-example_otfview.c,v 1.2 2019/05/29 12:54:10 ryoon Exp $

* Fix a runtime crash on NetBSD.

--- example/otfview.c.orig	2015-09-02 13:39:25.000000000 +0000
+++ example/otfview.c
@@ -28,6 +28,7 @@ write to the Free Software Foundation, I
 #include <sys/stat.h>
 #include <unistd.h>
 #include <libgen.h>
+#include <limits.h>
 
 #include "config.h"
 #ifdef HAVE_ALLOCA_H
@@ -1603,7 +1604,10 @@ ExposeProc (Widget w, XEvent *event, Str
 {
   XTextProperty text_prop;
   char *pname = "otfview";
-  char *fname = basename (filename);
+  char *tmpfname = basename (filename);
+  size_t len = strlen(tmpfname);
+  char fname[NAME_MAX];
+  snprintf(fname, len + 1, "%s", tmpfname);
   char *name = alloca (strlen (fname) + 3 + strlen (pname) + 1);
 
   sprintf (name, "%s - %s", pname, fname);
@@ -1735,7 +1739,9 @@ main (int argc, char **argv)
     char title[256];
     Arg arg[1];
 
-    filename = basename (filename);
+    char *tmpfilename = basename (filename);
+    size_t len = strlen(tmpfilename);
+    snprintf(filename, len + 1, "%s", tmpfilename);
     sprintf (title, "%s family:%s style:%s",
 	     filename, face->family_name, face->style_name);
     XtSetArg (arg[0], XtNtitle, title);
