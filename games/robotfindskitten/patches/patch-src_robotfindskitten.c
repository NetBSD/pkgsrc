$NetBSD: patch-src_robotfindskitten.c,v 1.2 2022/06/08 21:55:28 rillig Exp $

Fix compile warning on NetBSD due to use of time(3) without <time.h>.

--- src/robotfindskitten.c.orig	2007-12-01 04:25:21.000000000 +0000
+++ src/robotfindskitten.c
@@ -37,6 +37,7 @@ static char* ver = VERSION;
 
 #include <signal.h>
 #include <stdlib.h>
+#include <time.h>
 
 /*The messages go in a separate file because they are collectively
   huge, and you might want to modify them. It would be nice to load
