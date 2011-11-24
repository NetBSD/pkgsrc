$NetBSD: patch-krecipes_src_importers_kreimporter.h,v 1.1 2011/11/24 14:15:41 joerg Exp $

--- krecipes/src/importers/kreimporter.h.orig	2011-11-24 00:04:33.000000000 +0000
+++ krecipes/src/importers/kreimporter.h
@@ -46,7 +46,7 @@ private:
 	void readCategoryStructure( const QDomNodeList& l, CategoryTree *tree );
 	void readDescription( const QDomNodeList& l, Recipe* );
 	void readIngredients( const QDomNodeList& l, Recipe*, const QString &header = QString::null, Ingredient *ing = 0 );
-	void readAmount( const QDomElement& amount, double &amount, double &amount_offset );
+	void readAmount( const QDomElement& amount, double &amount2, double &amount_offset );
 	void readRatings( const QDomNodeList&, Recipe * );
 	void readCriterion( const QDomNodeList&, RatingCriteriaList &r );
 };
