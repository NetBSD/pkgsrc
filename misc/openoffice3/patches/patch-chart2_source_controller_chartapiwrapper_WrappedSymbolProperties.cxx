$NetBSD: patch-chart2_source_controller_chartapiwrapper_WrappedSymbolProperties.cxx,v 1.1 2013/04/01 12:19:13 joerg Exp $

--- chart2/source/controller/chartapiwrapper/WrappedSymbolProperties.cxx.orig	2013-03-30 18:10:05.000000000 +0000
+++ chart2/source/controller/chartapiwrapper/WrappedSymbolProperties.cxx
@@ -101,12 +101,6 @@ public:
     virtual ~WrappedSymbolBitmapURLProperty();
 };
 
-// this operator is not defined by default
-bool operator!=( const awt::Size & rSize1, const awt::Size & rSize2 )
-{
-    return (rSize1.Width != rSize2.Width) || (rSize1.Height != rSize2.Height);
-}
-
 class WrappedSymbolSizeProperty : public WrappedSeriesOrDiagramProperty< awt::Size >
 {
 public:
