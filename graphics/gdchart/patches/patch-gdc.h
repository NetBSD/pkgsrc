$NetBSD: patch-gdc.h,v 1.1 2001/10/18 11:13:56 darcy Exp $

--- gdc.h.orig	Mon Jun 18 00:51:01 2001
+++ gdc.h	Mon Jun 18 00:51:16 2001
@@ -9,7 +9,7 @@
 #define _GDC_H
 
 #include <math.h>
-#include <values.h>
+#include <limits.h>
 #ifdef GDC_INCL
 #include "gd.h"
 #include "gdfonts.h"
