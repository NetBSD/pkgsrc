$NetBSD: patch-es-core_src_components_ImageGridComponent.h,v 1.1 2015/02/21 02:01:59 joerg Exp $

--- es-core/src/components/ImageGridComponent.h.orig	2015-02-21 01:50:53.000000000 +0000
+++ es-core/src/components/ImageGridComponent.h
@@ -21,7 +21,7 @@ protected:
 	using IList<ImageGridData, T>::getTransform;
 	using IList<ImageGridData, T>::mSize;
 	using IList<ImageGridData, T>::mCursor;
-	using IList<ImageGridData, T>::Entry;
+	using typename IList<ImageGridData, T>::Entry;
 	using IList<ImageGridData, T>::mWindow;
 
 public:
