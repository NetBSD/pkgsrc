$NetBSD: patch-spunk_menuedit.h,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/menuedit.h.orig	1996-11-07 18:06:48.000000000 +0000
+++ spunk/menuedit.h
@@ -28,6 +28,7 @@
 #include "datetime.h"
 #include "charset.h"
 
+#undef CS
 
 
 /*****************************************************************************/
