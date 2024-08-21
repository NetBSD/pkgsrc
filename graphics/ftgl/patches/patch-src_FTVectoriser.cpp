$NetBSD: patch-src_FTVectoriser.cpp,v 1.1 2024/08/21 19:57:34 wiz Exp $

Fix build with freetype 2.13.3.

--- src/FTVectoriser.cpp.orig	2024-08-21 19:55:34.860855515 +0000
+++ src/FTVectoriser.cpp
@@ -166,7 +166,7 @@ void FTVectoriser::ProcessContours()
     for(int i = 0; i < ftContourCount; ++i)
     {
         FT_Vector* pointList = &outline.points[startIndex];
-        char* tagList = &outline.tags[startIndex];
+        char* tagList = (char *)&outline.tags[startIndex];
 
         endIndex = outline.contours[i];
         contourLength =  (endIndex - startIndex) + 1;
