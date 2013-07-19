$NetBSD: patch-src_x48_x11.c,v 1.2 2013/07/19 12:51:11 joerg Exp $

Pick X11 application defaults from path specified in the package
Makefile.

--- src/x48_x11.c.orig	2011-11-15 03:03:40.000000000 +0000
+++ src/x48_x11.c
@@ -1100,8 +1100,9 @@ char **argv;
     }
 
   /* 2. /usr/lib/X11/app-defaults/X48 */
+  /* Erm...  Rather, get this from package Makefile via CPPFLAGS */
 
-  merge_app_defaults("/usr/lib/X11/app-defaults", &rdb);
+  merge_app_defaults(X11APPDEFS, &rdb);
 
   /* 3. Values in $XUSERFILESEARCHPATH/X48, or $XAPPLRESDIR/X48 */
 
@@ -3833,7 +3834,7 @@ int first_key = 0;
 
 int last_button = -1;
 
-extern char *get_stack(void);
+extern void get_stack(void);
 
 int
 #ifdef __FunctionProto__
