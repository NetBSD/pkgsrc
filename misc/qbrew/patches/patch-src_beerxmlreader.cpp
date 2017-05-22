$NetBSD: patch-src_beerxmlreader.cpp,v 1.1 2017/05/22 23:40:22 joerg Exp $

--- src/beerxmlreader.cpp.orig	2017-05-21 18:14:47.418438605 +0000
+++ src/beerxmlreader.cpp
@@ -254,7 +254,7 @@ Recipe BeerXmlReader::readSingleRecipe()
     }
     if (hasError()) {
         raiseError("Problem reading recipe");
-        return false;
+        return Recipe(0);
     }
 
     // set grain use according to recipe type
