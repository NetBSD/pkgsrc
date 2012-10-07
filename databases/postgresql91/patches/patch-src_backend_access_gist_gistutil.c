$NetBSD: patch-src_backend_access_gist_gistutil.c,v 1.1 2012/10/07 10:24:54 marino Exp $

GCC 4.6 and GCC 4.7 do not consider the storage array has having a constant
size due to the macro definition of GEVHDRSZ found in gist.h
"gistutil.c:248:14: error: storage size of `storage` isn't constant"
Using an enumeration satisfies these compilers.

--- src/backend/access/gist/gistutil.c.orig	2012-09-19 21:50:31.000000000 +0000
+++ src/backend/access/gist/gistutil.c
@@ -244,8 +244,11 @@ gistMakeUnionKey(GISTSTATE *giststate, i
 {
 
 	int			dstsize;
+	enum {
+		GEV_STORAGE_SIZE = 2 * sizeof(GISTENTRY) + GEVHDRSZ
+	};
 
-	static char storage[2 * sizeof(GISTENTRY) + GEVHDRSZ];
+	static char storage[GEV_STORAGE_SIZE];
 	GistEntryVector *evec = (GistEntryVector *) storage;
 
 	evec->n = 2;
