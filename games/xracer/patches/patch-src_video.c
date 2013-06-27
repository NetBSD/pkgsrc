$NetBSD: patch-src_video.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/video.c.orig	2013-06-26 22:50:42.000000000 +0000
+++ src/video.c
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include <GL/glu.h>
 
