$NetBSD: patch-src_game.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/game.c.orig	2013-06-26 22:52:42.000000000 +0000
+++ src/game.c
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include <GL/glut.h>
 
