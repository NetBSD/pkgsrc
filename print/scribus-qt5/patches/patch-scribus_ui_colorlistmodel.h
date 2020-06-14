$NetBSD: patch-scribus_ui_colorlistmodel.h,v 1.1 2020/06/14 07:35:58 ryoon Exp $

* Fix segfault.

--- scribus/ui/colorlistmodel.h.orig	2020-06-11 09:56:15.000000000 +0000
+++ scribus/ui/colorlistmodel.h
@@ -103,12 +103,9 @@ protected:
 	// SortRule m_sortRule
 	SortRule m_sortRule;
 
-	//! Dummy object used to represent None Color
-	static ColorPixmapValue m_NoneColor;
-
 	static bool compareColorNames(const ColorPixmapValue& v1, const ColorPixmapValue& v2);
 	static bool compareColorValues(const ColorPixmapValue& v1, const ColorPixmapValue& v2);
 	static bool compareColorTypes(const ColorPixmapValue& v1, const ColorPixmapValue& v2);
 };
 
-#endif // COLORLISTMODEL_H
\ No newline at end of file
+#endif // COLORLISTMODEL_H
