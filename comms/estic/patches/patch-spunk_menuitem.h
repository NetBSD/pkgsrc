$NetBSD: patch-spunk_menuitem.h,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/menuitem.h.orig	1996-12-10 14:41:04.000000000 +0000
+++ spunk/menuitem.h
@@ -27,7 +27,7 @@
 #include "datetime.h"
 #include "charset.h"
 
-
+#undef CS
 
 /*****************************************************************************/
 /*                              class MenueLine                              */
