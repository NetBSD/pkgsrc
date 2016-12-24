$NetBSD: patch-PrefsSourceLib_XMLParser.cpp,v 1.1 2016/12/24 10:18:31 joerg Exp $

Pointers have no sign.

--- PrefsSourceLib/XMLParser.cpp.orig	2016-12-24 09:26:37.933694610 +0000
+++ PrefsSourceLib/XMLParser.cpp
@@ -656,7 +656,7 @@ void XMLTag::FormatData(ResizeableString
     
     if (fEmbeddedTags.GetLength() == 0)
     {
-        if (fValue > 0)
+        if (fValue != NULL)
             formatter->Put(fValue);
     }
     else
