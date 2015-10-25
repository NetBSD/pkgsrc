$NetBSD: patch-sanei_sanei__ir.c,v 1.1 2015/10/25 10:39:13 wiz Exp $

--- sanei/sanei_ir.c.orig	2015-09-29 01:10:43.000000000 +0000
+++ sanei/sanei_ir.c
@@ -29,7 +29,6 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <values.h>
 #include <math.h>
 
 #define BACKEND_NAME sanei_ir	/* name of this module for debugging */
