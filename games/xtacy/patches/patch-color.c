$NetBSD: patch-color.c,v 1.1 2021/12/30 00:43:35 nia Exp $

Need string.h for memcpy().

--- color.c.orig	1998-09-04 05:40:45.000000000 +0000
+++ color.c
@@ -7,6 +7,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include "trippy.h"
 
 #ifndef sgn
