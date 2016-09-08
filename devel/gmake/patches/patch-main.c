$NetBSD: patch-main.c,v 1.6 2016/09/08 22:46:58 joerg Exp $

* [SV 43434] Handle NULL returns from ttyname().

--- main.c.orig	2014-10-05 16:24:51.000000000 +0000
+++ main.c
@@ -1401,13 +1401,18 @@ main (int argc, char **argv, char **envp
 #ifdef HAVE_ISATTY
     if (isatty (fileno (stdout)))
       if (! lookup_variable (STRING_SIZE_TUPLE ("MAKE_TERMOUT")))
-        define_variable_cname ("MAKE_TERMOUT", TTYNAME (fileno (stdout)),
-                               o_default, 0)->export = v_export;
-
+        {
+          const char *tty = TTYNAME (fileno (stdout));
+          define_variable_cname ("MAKE_TERMOUT", tty ? tty : DEFAULT_TTYNAME,
+                                 o_default, 0)->export = v_export;
+        }
     if (isatty (fileno (stderr)))
       if (! lookup_variable (STRING_SIZE_TUPLE ("MAKE_TERMERR")))
-        define_variable_cname ("MAKE_TERMERR", TTYNAME (fileno (stderr)),
-                               o_default, 0)->export = v_export;
+        {
+          const char *tty = TTYNAME (fileno (stderr));
+          define_variable_cname ("MAKE_TERMERR", tty ? tty : DEFAULT_TTYNAME,
+                                 o_default, 0)->export = v_export;
+        }
 #endif
 
   /* Reset in case the switches changed our minds.  */
