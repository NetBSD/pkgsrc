$NetBSD: patch-.._spunk_menuedit.h,v 1.1 2012/02/16 16:47:58 hans Exp $

--- ../spunk/menuedit.h.orig	1996-11-07 18:06:48.000000000 +0100
+++ ../spunk/menuedit.h	2012-01-25 18:38:05.997403890 +0100
@@ -28,6 +28,7 @@
 #include "datetime.h"
 #include "charset.h"
 
+#undef CS
 
 
 /*****************************************************************************/
