$NetBSD: patch-src_Burlap_matrixfunc.c,v 1.1 2014/04/19 14:53:00 joerg Exp $

--- src/Burlap/matrixfunc.c.orig	2014-04-19 13:21:40.000000000 +0000
+++ src/Burlap/matrixfunc.c
@@ -25,6 +25,7 @@
  ************************************************************************/
 
 # include <math.h>
+# include <string.h>
 # include <time.h>
 # include "debug.h"
 # include "error.h"
