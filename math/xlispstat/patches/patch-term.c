$NetBSD: patch-term.c,v 1.1 2012/11/19 02:56:44 joerg Exp $

--- term.c.orig	2012-11-18 23:20:09.000000000 +0000
+++ term.c
@@ -48,9 +48,7 @@ int term = 1;  /* gives tek */
 #define NICE_LINE		0
 #define POINT_TYPES		6
 
-do_point(x,y,number)
-     int x,y;
-     int number;
+static void do_point(int x, int y, int number)
 {
   register int htic,vtic;
   register struct termentry *t;
