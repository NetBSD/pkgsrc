$NetBSD: patch-src_core_symbology-ng_qgssymbolv2.h,v 1.1 2013/01/10 23:58:30 joerg Exp $

--- src/core/symbology-ng/qgssymbolv2.h.orig	2012-12-25 15:11:12.000000000 +0000
+++ src/core/symbology-ng/qgssymbolv2.h
@@ -96,7 +96,7 @@ class CORE_EXPORT QgsSymbolV2
     //! @note added in 1.5
     void setRenderHints( int hints ) { mRenderHints = hints; }
     //! @note added in 1.5
-    int renderHints() { return mRenderHints; }
+    int renderHints() const { return mRenderHints; }
 
   protected:
     QgsSymbolV2( SymbolType type, QgsSymbolLayerV2List layers ); // can't be instantiated
