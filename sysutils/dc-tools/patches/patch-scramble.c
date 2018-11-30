$NetBSD: patch-scramble.c,v 1.2 2018/11/30 19:27:25 maya Exp $

--- scramble.c.orig	2018-11-30 08:21:21.000000000 -0800
+++ scramble.c	2018-11-30 08:21:35.000000000 -0800
@@ -1,5 +1,6 @@
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #define MAXCHUNK (2048*1024)
 
