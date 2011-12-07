$NetBSD: patch-main.c,v 1.1.2.2 2011/12/07 08:30:52 tron Exp $

--- main.c.orig	1998-04-16 01:17:10.000000000 +0000
+++ main.c
@@ -18,6 +18,7 @@
 #include <X11/Intrinsic.h>
 #include <X11/Shell.h>
 #include <X11/StringDefs.h>
+#include <ctype.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <time.h>
@@ -47,7 +48,7 @@ static char *appDefaults[] =
     NULL
 };
 
-gcFunction = 3;
+int gcFunction = 3;
 
 typedef struct {
     String visualType;
@@ -272,7 +273,7 @@ GetFutureVisual(Widget *toplevel, int de
 }
 
 
-void 
+int
 main(int argc, char *argv[])
 {
     Display *dpy;
