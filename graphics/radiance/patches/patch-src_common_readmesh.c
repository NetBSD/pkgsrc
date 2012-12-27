$NetBSD: patch-src_common_readmesh.c,v 1.1 2012/12/27 00:20:56 dholland Exp $

Don't abuse NULL.

--- src/common/readmesh.c~	2004-09-14 02:53:50.000000000 +0000
+++ src/common/readmesh.c
@@ -97,7 +97,7 @@ gettree()				/* get a pre-ordered octree
 		default:
 			mesherror(USER, "damaged mesh octree");
 	}
-	return (OCTREE)NULL; /* pro forma return */
+	return (OCTREE)0; /* pro forma return */
 }
 
 
