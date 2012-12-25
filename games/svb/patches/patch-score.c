$NetBSD: patch-score.c,v 1.1 2012/12/25 21:09:52 joerg Exp $

--- score.c.orig	2012-12-25 13:55:02.000000000 +0000
+++ score.c
@@ -36,6 +36,7 @@
  */
 
 #include	<stdio.h>
+#include	<stdlib.h>
 #include	<X11/Xos.h>
 #include	<X11/Xlib.h>
 #include	<X11/Xutil.h>
@@ -233,9 +234,7 @@ write_scores()
 /*
  * adds score to table
  */
-add_score(sc, ledge)
-    int         sc;
-    int         ledge;
+void add_score(int sc, int ledge)
 {
     int         i,
                 j;
