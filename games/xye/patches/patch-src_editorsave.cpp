$NetBSD: patch-src_editorsave.cpp,v 1.1 2013/06/13 21:42:22 joerg Exp $

--- src/editorsave.cpp.orig	2013-06-13 19:53:39.000000000 +0000
+++ src/editorsave.cpp
@@ -636,16 +636,16 @@ bool editor::save(const string &target, 
         }
         saveColorStuff(file, board);
     
-        int i,j;
+        int j;
         file << "\t<ground>\n";
         resetSavedPosition();
-        for (i=0;i<XYE_HORZ;i++) for (j=0;j<XYE_VERT;j++) saveGroundObject(file,editor::board->objects[i][j],i,XYE_VERT-j-1);
+        for (int i2=0;i2<XYE_HORZ;i2++) for (j=0;j<XYE_VERT;j++) saveGroundObject(file,editor::board->objects[i2][j],i2,XYE_VERT-j-1);
         file << "\t</ground>\n";
         file << "\t<objects>\n";
         resetSavedPosition();
-        for (i=0;i<XYE_HORZ;i++) for (j=0;j<XYE_VERT;j++)
+        for (int i2=0;i2<XYE_HORZ;i2++) for (j=0;j<XYE_VERT;j++)
         {
-            saveNormalObject(file,editor::board->objects[i][j],i,XYE_VERT-j-1);
+            saveNormalObject(file,editor::board->objects[i2][j],i2,XYE_VERT-j-1);
         }
         savePortals( file, editor::board);
         
