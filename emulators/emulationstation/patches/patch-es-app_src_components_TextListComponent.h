$NetBSD: patch-es-app_src_components_TextListComponent.h,v 1.1 2015/02/21 02:01:59 joerg Exp $

--- es-app/src/components/TextListComponent.h.orig	2015-02-21 01:49:13.000000000 +0000
+++ es-app/src/components/TextListComponent.h
@@ -31,7 +31,7 @@ protected:
 	using IList<TextListData, T>::getTransform;
 	using IList<TextListData, T>::mSize;
 	using IList<TextListData, T>::mCursor;
-	using IList<TextListData, T>::Entry;
+	using typename IList<TextListData, T>::Entry;
 
 public:
 	using IList<TextListData, T>::size;
