$NetBSD: patch-src_math.c,v 1.1 2013/06/27 15:49:43 joerg Exp $

--- src/math.c.orig	2013-06-26 22:51:55.000000000 +0000
+++ src/math.c
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <math.h>
 
 #include "xracer-math.h"
