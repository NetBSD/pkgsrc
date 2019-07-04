$NetBSD: patch-example_otfview.c,v 1.3 2019/07/04 13:26:59 ryoon Exp $

* Fix a runtime crash on NetBSD.

--- example/otfview.c.orig	2015-09-02 13:39:25.000000000 +0000
+++ example/otfview.c
@@ -51,6 +51,8 @@ write to the Free Software Foundation, I
 
 #include <otf.h>
 
+#define MY_NAME_MAX 1024
+
 #define CAST_FROM_XTPOINTER(TYPE, DATA, VAR)	\
   do {						\
     long TYPE temp = (long TYPE) (DATA);	\
@@ -1603,7 +1605,9 @@ ExposeProc (Widget w, XEvent *event, Str
 {
   XTextProperty text_prop;
   char *pname = "otfview";
-  char *fname = basename (filename);
+  char *tmpfname = basename (filename);
+  char fname[MY_NAME_MAX];
+  snprintf(fname, sizeof(fname), "%s", tmpfname);
   char *name = alloca (strlen (fname) + 3 + strlen (pname) + 1);
 
   sprintf (name, "%s - %s", pname, fname);
@@ -1735,9 +1739,11 @@ main (int argc, char **argv)
     char title[256];
     Arg arg[1];
 
-    filename = basename (filename);
+    char *tmpfilename = basename (filename);
+    char fname[MY_NAME_MAX];
+    snprintf(fname, sizeof(fname), "%s", tmpfilename);
     sprintf (title, "%s family:%s style:%s",
-	     filename, face->family_name, face->style_name);
+	     fname, face->family_name, face->style_name);
     XtSetArg (arg[0], XtNtitle, title);
     XtSetValues (shell, arg, 1);
   }
