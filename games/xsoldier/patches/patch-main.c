$NetBSD: patch-main.c,v 1.1 2015/10/06 22:10:02 leot Exp $

"wait.h" is no longer used and available.

--- main.c.orig	2006-09-16 09:20:54.000000000 +0000
+++ main.c
@@ -33,7 +33,6 @@
 /* DeleteAllStar */
 #include "star.h"
 #include "score.h"
-#include "wait.h"
 #include "graphic.h"
 #include "input.h"
 
