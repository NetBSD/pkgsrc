$NetBSD: patch-src_include_GraphicsBase.h,v 1.1 2015/05/26 13:38:20 jperkin Exp $

Fix symbol visibility.

--- src/include/GraphicsBase.h.orig	2015-03-18 23:02:13.000000000 +0000
+++ src/include/GraphicsBase.h
@@ -41,6 +41,6 @@ void unregisterBase(void); /* used in de
 
 void Rf_setBaseDevice(Rboolean val, pGEDevDesc dd); /* used in graphics.c */
 
-int baseRegisterIndex;
+extern int baseRegisterIndex;
 
 #endif /* R_GRAPHICSBASE_ */
