$NetBSD: patch-oox_source_drawingml_table_tablecell.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- oox/source/drawingml/table/tablecell.cxx.orig	2014-08-24 19:21:08.000000000 +0000
+++ oox/source/drawingml/table/tablecell.cxx
@@ -117,9 +117,9 @@ void applyTableStylePart( oox::drawingml
     if (rTableStylePart.getTextColor().isUsed())
         aTextCharProps.maCharColor = rTableStylePart.getTextColor();
     if( rTableStylePart.getTextBoldStyle().is_initialized() )
-        aTextCharProps.moBold = rTableStylePart.getTextBoldStyle();
+        aTextCharProps.moBold = *rTableStylePart.getTextBoldStyle();
     if( rTableStylePart.getTextItalicStyle().is_initialized() )
-        aTextCharProps.moItalic = rTableStylePart.getTextItalicStyle();
+        aTextCharProps.moItalic = *rTableStylePart.getTextItalicStyle();
 }
 
 void applyTableCellProperties( const Reference < ::com::sun::star::table::XCell >& rxCell, const TableCell& rTableCell )
