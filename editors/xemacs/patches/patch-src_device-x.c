$NetBSD: patch-src_device-x.c,v 1.1 2026/01/20 22:27:15 hauke Exp $

If XOpenDisplay() fails and there is an explicit zero screen number
supplied, retry without that screen number, all going well addressing
problems with macOS XQuartz and launchd sockets.

Cherry-picked from f7f8c7a6c53c2f33d9915554deb823675441925c

--- src/device-x.c.orig	2026-01-01 18:13:30.000000000 +0000
+++ src/device-x.c
@@ -466,7 +466,7 @@ x_init_device (struct device *d, Lisp_Ob
   Extbyte **argv;
   const char *app_class;
   const char *app_name;
-  const char *disp_name;
+  Extbyte *disp_name;
   Visual *visual = NULL;
   int depth = 8;		/* shut up the compiler */
   Colormap cmap;
@@ -555,6 +555,7 @@ x_init_device (struct device *d, Lisp_Ob
 
   LISP_STRING_TO_EXTERNAL (display, disp_name, Qctext);
 
+retry_without_screen:
   /*
    * Break apart the old XtOpenDisplay call into XOpenDisplay and
    * XtDisplayInitialize so we can figure out whether there
@@ -571,6 +572,22 @@ x_init_device (struct device *d, Lisp_Ob
 
   if (dpy == 0)
     {
+      size_t disp_name_len = strlen (disp_name);
+
+      /* Hauke Fath reports in #xemacs on libera.chat that XQuartz fails when
+         we supply the screen name explicitly, since it expects the
+         corresponding file name to exist
+         (e.g. "/private/tmp/com.apple.launchd.892T1F8SoB/org.xquartz:0.0"). If
+         we fail here (which is rare) and there is a zero screen (which
+         suggests we have appended the screen number), retry without the zero
+         screen. */
+      if (disp_name_len > 2
+          && !strcmp (disp_name + (int) disp_name_len - 2, ".0"))
+        {
+          disp_name[(int) disp_name_len - 2] = '\0';
+          goto retry_without_screen;
+        }
+
       suppress_early_error_handler_backtrace = 1;
       signal_simple_error ("X server not responding\n", display);
     }
