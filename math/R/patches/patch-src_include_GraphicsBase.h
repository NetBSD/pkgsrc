$NetBSD: patch-src_include_GraphicsBase.h,v 1.2 2016/07/26 04:53:33 wen Exp $

Fix symbol visibility.

--- src/include/GraphicsBase.h.orig	2015-08-25 22:15:17.000000000 +0000
+++ src/include/GraphicsBase.h
@@ -41,6 +41,6 @@ void unregisterBase(void); /* used in de
 
 void Rf_setBaseDevice(Rboolean val, pGEDevDesc dd); /* used in graphics.c */
 
-int baseRegisterIndex;
+extern int baseRegisterIndex;
 
 #endif /* R_GRAPHICSBASE_ */
