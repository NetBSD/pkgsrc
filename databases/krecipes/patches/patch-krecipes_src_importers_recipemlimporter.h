$NetBSD: patch-krecipes_src_importers_recipemlimporter.h,v 1.1 2011/11/24 14:15:41 joerg Exp $

--- krecipes/src/importers/recipemlimporter.h.orig	2011-11-24 00:06:44.000000000 +0000
+++ krecipes/src/importers/recipemlimporter.h
@@ -38,14 +38,14 @@ protected:
 private:
 	void readRecipemlDirections( const QDomElement& dirs );
 	void readRecipemlHead( const QDomElement& head );
-	void readRecipemlIng( const QDomElement& ing, Ingredient *ing = 0, const QString &header = QString::null );
+	void readRecipemlIng( const QDomElement& ing, Ingredient *ing2 = 0, const QString &header = QString::null );
 	void readRecipemlIngs( const QDomElement& ings );
 	void readRecipemlMenu( const QDomElement& menu );
 	void readRecipemlSrcItems( const QDomElement& sources );
 	void readRecipemlRecipe( const QDomElement& recipe );
 	void readRecipemlPreptime( const QDomElement &preptime );
 	void readRecipemlQty( const QDomElement &qty, Ingredient &ing );
-	void readRecipemlRange( const QDomElement& range, double &range, double &range_offset );
+	void readRecipemlRange( const QDomElement& range, double &range2, double &range_offset );
 
 	Recipe recipe;
 };
