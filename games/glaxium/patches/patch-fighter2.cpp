$NetBSD: patch-fighter2.cpp,v 1.1 2016/12/12 06:21:47 dholland Exp $

Use right array size; avoid running off the end.

--- fighter2.cpp~	2002-10-04 18:05:20.000000000 +0000
+++ fighter2.cpp
@@ -87,7 +87,7 @@ void Fighter2::initList()
 	 }
    
     
-    for (i=0;i<587;i++) {
+    for (i=0;i<578;i++) {
         fighter2_meshes[i*24+7] = 1 - fighter2_meshes[i*24+7];
         fighter2_meshes[i*24+7+8] = 1 - fighter2_meshes[i*24+7+8];
         fighter2_meshes[i*24+7+16] = 1 - fighter2_meshes[i*24+7+16];
