$NetBSD: patch-source_third__party_mikktspace_weldmesh.cpp,v 1.1 2023/05/04 15:20:52 nikita Exp $

--- source/third_party/mikktspace/weldmesh.cpp.orig	2013-12-06 00:42:50.000000000 +0000
+++ source/third_party/mikktspace/weldmesh.cpp
@@ -30,7 +30,7 @@
 #include <string.h>
 #include <assert.h>
 
-#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <stdlib.h>  /* BSD-based OSes get their malloc stuff through here */
 #else
 #include <malloc.h> 
@@ -199,4 +199,3 @@ static void MergeVertsFast(int * piCurNr
 						   pfVertexDataIn, iNrVerticesIn, iFloatsPerVert, iL, iR_in, iChannelNum);	// weld all right of (or equal to) fSep
 	}
 }
-
