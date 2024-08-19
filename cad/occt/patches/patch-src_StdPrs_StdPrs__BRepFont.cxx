$NetBSD: patch-src_StdPrs_StdPrs__BRepFont.cxx,v 1.1 2024/08/19 17:13:49 tnn Exp $

fix fallout from freetype2 update

--- src/StdPrs/StdPrs_BRepFont.cxx.orig	2024-08-19 17:07:23.309314002 +0000
+++ src/StdPrs/StdPrs_BRepFont.cxx
@@ -457,7 +457,7 @@ Standard_Boolean StdPrs_BRepFont::render
   for (short aContour = 0, aStartIndex = 0; aContour < anOutline->n_contours; ++aContour)
   {
     const FT_Vector* aPntList = &anOutline->points[aStartIndex];
-    const char* aTags      = &anOutline->tags[aStartIndex];
+    const char* aTags      = (const char*)&anOutline->tags[aStartIndex];
     const short anEndIndex = anOutline->contours[aContour];
     const short aPntsNb    = (anEndIndex - aStartIndex) + 1;
     aStartIndex = anEndIndex + 1;
