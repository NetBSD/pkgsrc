$NetBSD: patch-lib3d_xform.C,v 1.1 2011/11/25 21:50:31 joerg Exp $

--- lib3d/xform.C.orig	2011-11-25 15:16:31.000000000 +0000
+++ lib3d/xform.C
@@ -4,7 +4,7 @@
 
 
 #include <math.h>
-#include <iomanip.h>
+#include <iomanip>
 #include "xform.h"
 
 
