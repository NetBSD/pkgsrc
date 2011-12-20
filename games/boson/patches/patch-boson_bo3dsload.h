$NetBSD: patch-boson_bo3dsload.h,v 1.1 2011/12/20 10:35:09 wiz Exp $

Avoid duplicate name in declaration.

--- boson/bo3dsload.h.orig	2003-01-07 07:20:47.000000000 +0000
+++ boson/bo3dsload.h
@@ -86,9 +86,9 @@ protected:
 	void loadFrame(int frame);
 	void countNodes(Lib3dsNode* node, int* count);
 	void loadFrameNode(BoFrame* frame, int* index, Lib3dsNode* node);
-	void loadVertices(BoMesh* mesh, Lib3dsMesh* mesh);
-	void loadTexels(BoMesh* mesh, Lib3dsMesh* mesh, Lib3dsMaterial* material);
-	void loadFaces(BoMesh* mesh, Lib3dsMesh* mesh);
+	void loadVertices(BoMesh* bomesh, Lib3dsMesh* mesh);
+	void loadTexels(BoMesh* bomesh, Lib3dsMesh* mesh, Lib3dsMaterial* material);
+	void loadFaces(BoMesh* bomesh, Lib3dsMesh* mesh);
 
 	/**
 	 * Render the specified node according to the values for the current
